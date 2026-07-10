#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT "4444"


int main(int argc, char *argv[]){
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char r_buff[100] = "", s_buff[100] = "";

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    connect(sockfd, (struct sockaddr *)&hints, sizeof hints);

    while(1){
        printf("\nclient");
        fgets(s_buff, sizeof s_buff, stdin);
        send(sockfd, s_buff, sizeof s_buff, 0);
        if (strcmp(r_buff, "exit") == 0)
            break;


        recv(sockfd, r_buff, sizeof r_buff, 0);
        printf("[server]: %s", r_buff);
        if (strcmp(r_buff, "exit") == 0)
            break;

        printf("\n");
    }

    close(sockfd);

    return 0;
}
