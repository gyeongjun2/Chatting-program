#include "chatheader_srv.h"
#include <pthread.h>


struct cli_info client[MAX_CLI];
int cnum = 0;

void *client_handler(void *arg){
    int client_index = *(int*)arg;
    free(arg);

    while(1){
        recv_mesg(client_index);
    }
    return NULL;
}



void acceptcli(int sockfd){

    int *cli_index;
    int cli_sock;
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);

    printf("Multi Chatting Server Running ...\n");

    while(1){
        cli_sock = accept(sockfd,(struct sockaddr*)&cli_addr,&cli_len);

        cli_index = malloc(sizeof(int));
        *cli_index = cnum;

        client[cnum].clisock = cli_sock;

        if(recv(cli_sock, client[cnum].alias,MAXMSG,0)<0){
            errmesg("server : recv() error");
            close(cli_sock);
            free(cli_index);
            continue;
        }
        printf("%s Join\n", client[cnum].alias);

        char conmesg[MAXMSG];
        sprintf(conmesg,"'%s'이(가) 채팅에 참여하였습니다.\n", client[cnum].alias);
        allclisend(cnum, conmesg);

        pthread_t t1;
        if(pthread_create(&t1, NULL, client_handler, cli_index)!=0){
            errmesg("server : pthread_crate() error");
        }

        pthread_detach(t1);

        cnum++;
    }
}
