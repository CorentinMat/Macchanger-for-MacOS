

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <net/if_dl.h>
#include <ifaddrs.h>
#include <errno.h>
#include <string.h>

#include "netinfo.h"
#include "mac.h"
#include "netinfo.h"

unsigned char *get_mac_address(void)
{

    struct ifaddrs *if_addrs = NULL;

    static unsigned char mac[6];
    if (0 == getifaddrs(&if_addrs))
    {

        // MAC address
        if (if_addrs[21].ifa_addr != NULL && if_addrs[21].ifa_addr->sa_family == AF_LINK)
        {
            // printf("\nfamily : %hhu\n", if_addrs[21].ifa_addr->sa_family = 18);
            struct sockaddr_dl *sdl = (struct sockaddr_dl *)if_addrs[21].ifa_addr;
            if (6 == sdl->sdl_alen)
            {
                memcpy(mac, LLADDR(sdl), sdl->sdl_alen);
            }

            printf("\n");
        }
        return mac;

        freeifaddrs(if_addrs);
        if_addrs = NULL;
    }
    else
    {
        printf("getifaddrs() failed with errno =  %i %s\n", errno, strerror(errno));
        return NULL;
    }
}

int set_mac(net_info *net, const mac_t *macFaked)
{
    char command[100];
    char interface[4] = "en0";

    // Disconnect from active Wifi on en0
    snprintf(command, sizeof(command), "sudo ./src/shut_down_wifi.sh");
    system(command);

    // Change MAC Address
    snprintf(command, sizeof(command), "sudo ifconfig %s ether %02x:%02x:%02x:%02x:%02x:%02x", interface, macFaked->byte[0], macFaked->byte[1], macFaked->byte[2], macFaked->byte[3], macFaked->byte[4], macFaked->byte[5]);
    system(command);

    printf("Adresse MAC de %s modifiée avec succès en %02x:%02x:%02x:%02x:%02x:%02x\n", interface, macFaked->byte[0], macFaked->byte[1], macFaked->byte[2], macFaked->byte[3], macFaked->byte[4], macFaked->byte[5]);

    return EXIT_SUCCESS;

    return 0;
}