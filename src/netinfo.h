
#ifndef __MAC_CHANGER_NETINFO_H__
#define __MAC_CHANGER_NETINFO_H__

#include <sys/socket.h>
#include <net/if.h>
#include "mac.h"

typedef struct
{
    int sock;
    struct ifreq dev;
} net_info;
unsigned char *get_mac_address(void);
int set_mac(net_info *net, const mac_t *macFaked);

#endif