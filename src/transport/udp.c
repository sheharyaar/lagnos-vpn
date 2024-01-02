#include "./udp.h"

#include <arpa/inet.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

void read_tun(VPN_CTX ctx) {
    if (ctx->tun_fd < 0) {
        log_error("invalid tunnel fd");
    }
    char buf[2000];
    int bytes_read;

    uint16_t proto, flags;
    while (1) {
        if ((bytes_read = read(ctx->tun_fd, buf, sizeof(buf))) < 0) {
            log_error("error in read : %s", strerror(errno));
            return;
        }

        // we ignore flags
        memcpy(&flags, buf, 2);
        memcpy(&proto, buf + 2, 2);

        if (proto == 0x86dd) {
            log_error("IPv6 is not supported");
            continue;
        }

        proto = ntohs(proto);
        if (proto == 0x0800) {
            log_debug("IPv4 packet received with size : %d", bytes_read - 4);

            if (bytes_read - 4 > TUN_MTU) {
                log_error("packet greater than MTU");
            }
            }
    }
}