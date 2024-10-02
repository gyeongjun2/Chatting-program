#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct cli_info{

	char alias[30];
	int clisock;

};

#define MAX_CLI 50
#define MAXMSG 256

#define errmesg(MSG) {printf("%s\n",MSG); exit(1);}

void add_client(int newsockfd);
void acceptcli(int sockfd);
void recv_mesg(int num);
void allclisend(int num, char *message);


