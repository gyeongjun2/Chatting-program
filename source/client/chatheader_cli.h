#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define MAXMSG 128
#define errmesg(MSG) {printf("%s\n",MSG); exit(1);}

void doChat(int sockfd, char *alias);

