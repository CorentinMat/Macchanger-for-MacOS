// #include <stdio.h>
// #include "netinfo.h"
// int main(int argc, char *argv[])
// {

//     printf("argument 1 : %s\n", argv[1]);
//     net_info *net;
//     mac_t *mac;

//     mac = get_mac_address(net);
//     char str[12];

//     sprintf(str, "%d", mac);
//     printf(" mac address: %s\n", str);
//     return 0;
//}
#include <stdio.h>
#include <stdlib.h>
#include "netinfo.h"

int main()
{

    net_info *net;

    unsigned char *mac;
    mac_t *macFaked;

    mac_random(macFaked, 3, 1);
    printf("\nmac faked  : %02x:%02x:%02x:%02x:%02x:%02x\n", macFaked->byte[0], macFaked->byte[1], macFaked->byte[2], macFaked->byte[3], macFaked->byte[4], macFaked->byte[5]);

    mac = get_mac_address();
    printf("\nOld mac  : %02x:%02x:%02x:%02x:%02x:%02x\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

    int err = set_mac(net, macFaked);
    if (err != 0)
    {
        printf("\nChanging Mac Address failed 🤦‍♂️\n");
    }
}