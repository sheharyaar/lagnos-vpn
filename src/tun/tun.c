#include "./tun.h"

#include <errno.h>
#include <fcntl.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <stddef.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

int tun_alloc(VPN_CTX ctx) {
    /* Check if dev_name exists*/
    if (ctx->tun_name[0] == 0 || ctx->tun_name[0] == ' ') {
        log_debug("tun_name is empty, setting to lagnos-tun");
        strncpy(ctx->tun_name, "lagnos-tun", strlen("lagnos-tun") + 1);
    }

    struct ifreq ifr;
    int err;

    if ((ctx->tun_fd = open("/dev/net/tun", O_RDWR)) < 0) {
        log_error("error in opening /dev/net/tun : %s", strerror(errno));
        return -1;
    }

    memset(&ifr, 0, sizeof(ifr));

    /* Flags: IFF_TUN   - TUN device (no Ethernet headers)
     *        IFF_TAP   - TAP device
     *        IFF_NO_PI - Do not provide packet information
     */
    ifr.ifr_flags = IFF_TUN;
    strncpy(ifr.ifr_name, ctx->tun_name, IFNAMSIZ);

    if ((err = ioctl(ctx->tun_fd, TUNSETIFF, (void *)&ifr)) < 0) {
        log_error("error in ioctl : %s", strerror(errno));
        close(ctx->tun_fd);
        return err;
    }
    strncpy(ctx->tun_name, ifr.ifr_name, IFNAMSIZ);
    return 0;
}

void tun_close(VPN_CTX ctx) {
    log_debug("closing tunnel");
    close(ctx->tun_fd);
}
