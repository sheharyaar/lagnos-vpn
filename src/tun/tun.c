#include "./tun.h"

#include <errno.h>
#include <fcntl.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <stddef.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

int tun_alloc(VPN_CTX ctx, char *dev) {
    /* Check if dev_name exists*/
    if (ctx->tun_name[0] == 0 || ctx->tun_name[0] == ' ') {
        log_debug("tun_name is empty");
        return -1;
    }

    struct ifreq ifr;
    int fd, err;

    if ((fd = open("/dev/net/tun", O_RDWR)) < 0) {
        log_error("error in opening /dev/net/tun", strerror(errno));
        return -1;
    }

    memset(&ifr, 0, sizeof(ifr));

    /* Flags: IFF_TUN   - TUN device (no Ethernet headers)
     *        IFF_TAP   - TAP device
     *        IFF_NO_PI - Do not provide packet information
     */
    ifr.ifr_flags = IFF_TUN;
    if (*dev) strncpy(ifr.ifr_name, dev, IFNAMSIZ);

    if ((err = ioctl(fd, TUNSETIFF, (void *)&ifr)) < 0) {
        close(fd);
        return err;
    }
    strcpy(dev, ifr.ifr_name);
    return fd;
}
