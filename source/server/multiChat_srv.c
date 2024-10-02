#include "chatheader_srv.h"

int main(int argc, char *argv[]){

	int sockfd, port;
	struct sockaddr_in cli_addr, serv_addr;

	//input port number
	printf("Input port number: ");
	if(scanf("%d", &port)!=1){
		errmesg("server : port number input error");
	}

	//create socket
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1){
		errmesg("server : socket() error");
	}

	//setting server addr
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);

	//bind socket
	if(bind(sockfd,(struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1){
		errmesg("server : bind() error");
	}

	listen(sockfd, 5);
	acceptcli(sockfd);
	close(sockfd);
	



}
