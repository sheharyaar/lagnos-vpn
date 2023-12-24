#ifndef _LAGNOS_VPN
#define _LAGNOS_VPN

#include "./log/log.h"

typedef struct vpn_ctx {
    /* tunnel context */
    char tun_name[16];
    int tun_fd;

    /* transport context */

} *VPN_CTX;

#endif