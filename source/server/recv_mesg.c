#include "chatheader_srv.h"

extern struct cli_info client[];
extern int cnum;

void allclisend(int num, char *message);

void recv_mesg(int num){

	int len;
	char mesg[MAXMSG], realmsg[MAXMSG];

	memset(mesg, '\0', sizeof(mesg));
	memset(realmsg, '\0', sizeof(realmsg));

	if((len = recv(client[num].clisock, mesg, MAXMSG, 0))<0)
		errmesg("server : message read error");
	
	if(len==0)
		return;
	
	//if message is "quit"
	if(!strncmp(mesg,"quit",4)){
		sprintf(realmsg,"알림 - [%s]님이 채팅방을 나갔습니다.\0", client[num].alias);
		printf("%s Disconnect\n", client[num].alias);
		allclisend(num, realmsg);
		client[num] = client[--cnum];
	}
	else if(strncmp(mesg,"/w", 2)==0){
	
		char *receiver_alias, *private_msg;

		strtok(mesg," ");	
		receiver_alias = strtok(NULL," ");
		private_msg = strtok(NULL, "");

		if(receiver_alias && private_msg){
			for(int i=0;i<cnum;i++){
				if(strcmp(client[i].alias, receiver_alias)==0){
					sprintf(realmsg,"[%s의 귓속말] : %s\n", client[num].alias, private_msg);
					send(client[i].clisock, realmsg, strlen(realmsg),0);
					sprintf(realmsg,"[%s에게 보낸 귓속말]: %s\n", client[i].alias, private_msg);
					send(client[num].clisock, realmsg, strlen(realmsg),0);
					return;
				}
			}
			sprintf(realmsg, "유저 '%s'을(를) 찾을 수 없습니다.\n", receiver_alias);
			send(client[num].clisock, realmsg, strlen(realmsg),0);
		}else{
			sprintf(realmsg, "귓속말 사용법 : /w <별명> <메세지>\n");
			send(client[num].clisock, realmsg, strlen(realmsg),0);
		}
	}
	else{
		sprintf(realmsg,"[ %-10s ] : ",client[num].alias);
		mesg[len] = '\0';
		strcat(realmsg, mesg);
		allclisend(num, realmsg);
	}

}

//send message all client
void allclisend(int num, char *message){

	int i, len;
	len = strlen(message);
	message[len] = '\0';
	for(i=0;i<cnum;i++){
		if(i==num)
			continue;
		send(client[i].clisock, message, len, 0);
	}
}


