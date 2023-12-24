#ifndef _LAGNOS_TUN
#define _LAGNOS_TUN

#include "../vpn.h"

/*
 * Allocates a tunnel device for this program
 *
 * Arguments:
 * char *dev - a mutable character array, the function sets the assigned device
 *              to this string
 *
 * Returns :
 * < 0 on error
 * fd on success
 */
int tun_alloc(VPN_CTX ctx);

void tun_close(VPN_CTX ctx);

#endif