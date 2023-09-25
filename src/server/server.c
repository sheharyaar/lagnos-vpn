#include "server.h"

/* Callback functions */
static he_return_code_t server_event_cb(he_conn_t *conn, he_conn_event_t event,
                                        void *context) {
    fprintf(stderr, "[LOG] event occured %s\n", he_client_event_name(event));
    return HE_SUCCESS;
}

static he_return_code_t server_nudge_cb(he_conn_t *conn, int timeout,
                                        void *context) {
    fprintf(stderr, "[LOG] nudge time %d\n", timeout);
    return HE_SUCCESS;
}

static he_return_code_t server_state_cb(he_conn_t *conn,
                                        he_conn_state_t new_state,
                                        void *context) {
    fprintf(stderr, "[LOG] state changed %s\n",
            he_client_state_name(new_state));
    return HE_SUCCESS;
}

static bool auth_cb(he_conn_t *conn, char const *username, char const *password,
                    void *context) {
    return HE_SUCCESS;
}

static he_return_code_t populate_network_config_cb(
    he_conn_t *he_conn, he_network_config_ipv4_t *config, void *context) {
    fprintf(stderr, "[LOG] populating network config\n");
    return HE_SUCCESS;
}

/* Exported functions */
he_ssl_ctx_t *server_init() {
    fprintf(stdout, "-- initialising lagnos vpn server\n");

    // Configuring helium ssl context
    he_ssl_ctx_t *ssl_ctx = he_ssl_ctx_create();
    if (!ssl_ctx) {
        fprintf(stderr, "failed to create SSL context\n");
        return NULL;
    }

    // ssl context options
    he_return_code_t ret;

    // version
    ret = he_ssl_ctx_set_minimum_supported_version(ssl_ctx, 1, 2);
    if (ret != HE_SUCCESS) {
        fprintf(stderr, "failed to set minimum supported version, error=%d\n",
                ret);
        return NULL;
    }

    // cypher
    ret = he_ssl_ctx_set_use_chacha20(ssl_ctx, 1);
    if (ret != HE_SUCCESS) {
        fprintf(stderr, "failed to set use_chacha20 error=%d\n", ret);
        return NULL;
    }

    // connection type
    ret = he_ssl_ctx_set_connection_type(ssl_ctx, HE_CONNECTION_TYPE_STREAM);
    if (ret != HE_SUCCESS) {
        fprintf(stderr, "failed to set connection_type to STREAM, error=%d\n",
                ret);
        return NULL;
    }

    // event cb
    he_ssl_ctx_set_event_cb(ssl_ctx, server_event_cb);

    // state change cb
    he_ssl_ctx_set_state_change_cb(ssl_ctx, server_state_cb);

    // nudge time cb
    he_ssl_ctx_set_nudge_time_cb(ssl_ctx, server_nudge_cb);

    // TODO: inside write cb

    // TODO: outside write cb

    // set certificates
    ret = he_ssl_ctx_set_server_cert_key_files(ssl_ctx, "cert.pem", "key.pem");
    if (ret != HE_SUCCESS) {
        fprintf(stderr, "failed to set server cert and key files, error=%d\n",
                ret);
        return NULL;
    }

    he_ssl_ctx_set_auth_cb(ssl_ctx, auth_cb);

    he_ssl_ctx_set_populate_network_config_ipv4_cb(ssl_ctx,
                                                   populate_network_config_cb);

    // sanity check
    ret = he_ssl_ctx_is_valid_server(ssl_ctx);
    if (ret != HE_SUCCESS) {
        fprintf(stderr, "the server initialisation is not valid, error=%d\n",
                ret);
        return NULL;
    }

    return ssl_ctx;
}

he_return_code_t server_start(he_ssl_ctx_t *ssl_ctx) {
    he_return_code_t ret;
    fprintf(stdout, "-- starting lagnos vpn server\n");

    ret = he_ssl_ctx_start_server(ssl_ctx);
    if (ret != HE_SUCCESS) {
        fprintf(stderr, "failed to start server, error=%d\n", ret);
        return ret;
    }
    return HE_SUCCESS;
}

void server_cleanup(he_ssl_ctx_t *ssl_ctx) {
    fprintf(stdout, "-- cleaning up lagnos vpn server\n");
    if (ssl_ctx) he_free(ssl_ctx);
}