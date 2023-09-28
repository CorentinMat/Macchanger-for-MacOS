#include "mac.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void mac_random(mac_t *mac, unsigned char last_n_bytes, char set_bia)
{

    /* The LSB of first octet can not be set.  Those are musticast
     * MAC addresses and not allowed for network device:
     * x1:, x3:, x5:, x7:, x9:, xB:, xD: and xF:
     */
    srandom(getpid());

    switch (last_n_bytes)
    {
    case 6:
        /* 8th bit: Unicast / Multicast address
         * 7th bit: BIA (burned-in-address) / locally-administered
         */
        mac->byte[0] = (random() % 255) & 0xFC;

        mac->byte[1] = random() % 255;
        mac->byte[2] = random() % 255;
    /* To have the same Company maker*/
    case 3:
        mac->byte[3] = random() % 255;
        mac->byte[4] = random() % 255;
        mac->byte[5] = random() % 255;
    }

    /* Handle the burned-in-address bit
     */
    if (set_bia)
    {
        mac->byte[0] &= ~2;
    }
    else
    {
        mac->byte[0] |= 2;
    }
}