/* server.h */
#ifndef LAGNOS_SERVER_H
#define LAGNOS_SERVER_H

#include <helium/he.h>
#include <stdio.h>

he_ssl_ctx_t *server_init();
he_return_code_t server_start();
void server_cleanup(he_ssl_ctx_t *ssl_ctx);

#endif /* LAGNOS_SERVER_H */