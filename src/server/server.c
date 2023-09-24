#include "server.h"

he_return_code_t server_init() {
    fprintf(stdout, "-- initialising lagnos vpn server\n");

    // Configuring helium ssl context
    he_ssl_ctx_t *ssl_ctx = he_ssl_ctx_create();
    if (!ssl_ctx) {
        fprintf(stderr, "failed to create SSL context\n");
        return HE_ERR_SSL_OUT_OF_MEMORY;
    }

    // ssl context options
    he_return_code_t ret;
    ret = he_ssl_ctx_set_use_chacha20(ssl_ctx, 1);
    if (ret != HE_SUCCESS) {
        fprintf(stderr, "failed to set use_chacha20 error=%d\n", ret);
        return ret;
    }

    ret = he_ssl_ctx_set_connection_type(ssl_ctx, HE_CONNECTION_TYPE_STREAM);
    if (ret != HE_SUCCESS) {
        fprintf(stderr, "failed to set connection_type to STREAM, error=%d\n",
                ret);
        return ret;
    }

    ret = he_ssl_ctx_is_valid_server(ssl_ctx);
    if (ret != HE_SUCCESS) {
        fprintf(stderr, "the server initialisation is not valid, error=%d\n",
                ret);
        return ret;
    }

    return HE_SUCCESS;
}