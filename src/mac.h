#ifndef __MAC_CHANGER_MAC_H__
#define __MAC_CHANGER_MAC_H__

typedef struct
{
	unsigned char byte[6];
} mac_t;

void mac_random(mac_t *mac, unsigned char last_n_bytes, char set_bia);

#endif