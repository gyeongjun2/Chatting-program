#include "chatheader_cli.h"


void doChat(int sockfd, char *alias){

	int msglen, pid;
	char sndmsg[MAXMSG], recvmsg[MAXMSG];
	
	fd_set read_fdset, reset;
	int maxfdp1;


	if(write(sockfd, alias,strlen(alias)+1) != strlen(alias)+1)
		errmesg("client : alias send error");

	printf("\n채팅 나가기 - quit\n");
	printf("귓속말 - /w <nickname> <message>\n");

	FD_ZERO(&read_fdset);
	FD_SET(0, &read_fdset);
	FD_SET(sockfd, &read_fdset);
	reset = read_fdset;
	maxfdp1 = sockfd + 1;

	signal(SIGINT, SIG_IGN);

	while(1){
		fprintf(stderr,"[ %-10s ] : ", alias);

		read_fdset = reset;
		if(select(maxfdp1, &read_fdset, NULL, NULL, NULL)<0){
			printf("select error\n");
			exit(1);
		}
		//입력된 메시지
		if(FD_ISSET(0, &read_fdset)){
			memset(sndmsg, '\0', sizeof(sndmsg));
			fgets(sndmsg, sizeof(sndmsg), stdin);
			sndmsg[strlen(sndmsg)-1] = '\0';
			msglen = strlen(sndmsg);
			if(write(sockfd, sndmsg, msglen)!= msglen)
				errmesg("client : message send error");
			if(!strcmp(sndmsg,"quit")){
				printf("채팅방을 나갔습니다.\n");
				return;
			}
		}
		//서버에서 온 메시지
		if(FD_ISSET(sockfd, &read_fdset)){
			memset(recvmsg, '\0', sizeof(recvmsg));
			if(read(sockfd, recvmsg, MAXMSG+1)<=0)
				errmesg("client : message receive error");

			msglen = strlen(recvmsg);
			recvmsg[msglen] = '\0';
			printf("\n%s\n",recvmsg);
		}

	}

}
