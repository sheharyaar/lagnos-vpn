#include <stdio.h>
#include <stdlib.h>

#include "./transport/udp.h"
#include "./tun/tun.h"

/*
 *  Usage : ./lagnos-vpn <server/client> <udp/tcp> <port>
 */
void print_usage() {
    fprintf(stdout, "Usage : lagnos-vpn <server/client> <udp/tcp> <port>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        exit(1);
    }

    VPN_CTX ctx = (VPN_CTX)malloc(sizeof(struct vpn_ctx));

    // allocate tunnel
    int tun_fd = tun_alloc(ctx);
    if (tun_fd < 0) {
        log_error("unable to allocate tunnel\n");
        exit(1);
    }
    log_info("tunnel=%s created", ctx->tun_name);

    read_tun(ctx);

    log_info("closing tunnel, bye bye!");
    tun_close(ctx);

    return 0;
}