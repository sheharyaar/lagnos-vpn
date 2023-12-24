#include "./udp.h"

#include <errno.h>
#include <string.h>
#include <unistd.h>

void read_tun(VPN_CTX ctx) {
    if (ctx->tun_fd < 0) {
        log_error("invalid tunnel fd");
    }
    char buf[1400];
    int bytes_read;

    while (1) {
        if ((bytes_read = read(ctx->tun_fd, buf, sizeof(buf))) < 0) {
            log_error("error in read : %s", strerror(errno));
            return;
        }

        for (int i = 0; i < bytes_read; i++) printf("%c ", buf[i]);
    }
}