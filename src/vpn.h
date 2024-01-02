#ifndef _LAGNOS_VPN_H
#define _LAGNOS_VPN_H

#include "./log/log.h"

typedef struct vpn_ctx {
    /* tunnel context */
    char tun_name[16];
    int tun_fd;

    /* transport context */

} *VPN_CTX;

#endif