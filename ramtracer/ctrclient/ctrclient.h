#ifndef __CTRCLIENT_H__
#define __CTRCLIENT_H__

#define AES_FLAGS_SET_IV		1
#define AES_FLAGS_SET_KEY		2
#define AES_FLAGS_SET_YKEY		4
#define AES_FLAGS_SELECT_KEY	8

#define MAX_CHALLENGESIZE		0x100

typedef struct
{
	int sockfd;
} ctrclient;

typedef struct
{
	unsigned char flags[4];
	unsigned char keyslot[4];
	unsigned char key[16];
	unsigned char iv[16];
} aescontrol;

// Maximum size per message
#define CHUNKMAXSIZE		0xFFF000

void ctrclient_init();
void ctrclient_disconnect(ctrclient* client);
int ctrclient_connect(ctrclient* client, const char* hostname, const char* port);
int ctrclient_sendbuffer(ctrclient* client, const void* buffer, unsigned int size);
int ctrclient_recvbuffer(ctrclient* client, void* buffer, unsigned int size);
int ctrclient_sendlong(ctrclient* client, unsigned int value);
int ctrclient_aes_ctr_crypt(ctrclient* client, unsigned char* buffer, unsigned int size);
int ctrclient_aes_set_key(ctrclient* client, unsigned int keyslot, unsigned char key[16]);
int ctrclient_aes_set_ykey(ctrclient* client, unsigned int keyslot, unsigned char key[16]);
int ctrclient_aes_select_key(ctrclient* client, unsigned int keyslot);
int ctrclient_aes_set_iv(ctrclient* client, unsigned char iv[16]);
int ctrclient_aes_set_ctr(ctrclient* client, unsigned char ctr[16]);

#endif // __CTRCLIENT_H__