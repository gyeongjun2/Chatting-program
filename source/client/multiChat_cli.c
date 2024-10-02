#include "chatheader_cli.h"

int main(int argc, char *argv[]){

	int sockfd, port;
	char alias[30], host[50];

	struct sockaddr_in serv_addr;
	struct hostent *hostname;
	struct in_addr in;

	if(argc!=2){
		printf("Usage : %s [server address]\n", argv[0]);
		return 0;
	}

	printf("채팅서버의 포트번호를 입력하세요 : ");
	if(scanf("%d", &port)!=1){
		errmesg("client : port number input error");
	}
	while(getchar()!='\n');

	do{
		printf("사용할 별명을 입력하세요 :");
		fgets(alias, sizeof(alias), stdin);

	}while(strlen(alias)-1<=0);
	alias[strlen(alias)-1] = '\0';

	hostname = gethostbyname(argv[1]);
	memcpy(&in.s_addr, hostname->h_addr_list[0], sizeof(in.s_addr));

	bzero((char*)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(port);
	
	if((sockfd = socket(AF_INET, SOCK_STREAM,0))<0)
		errmesg("client : cant open stream socket");
	
	if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
		errmesg("client : connect() error");

	doChat(sockfd, alias);

	close(sockfd);

}
