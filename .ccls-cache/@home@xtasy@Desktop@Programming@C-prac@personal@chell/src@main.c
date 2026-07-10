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
#define BACKLOG 10

int main(int argc, char *argv[]) {
    struct sockaddr_storage the_addr;
    socklen_t addr_size;
    struct addrinfo hints, *servinfo, *res;
    int sockfd, newfd;

    char r_buff[100] = "", s_buff[100] = "";

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;


   sockfd = socket(hints.ai_family, hints.ai_socktype, 0);
   bind(sockfd, res->ai_addr, res->ai_addrlen);


   listen(sockfd, BACKLOG);

   addr_size = sizeof the_addr;
   newfd = accept(sockfd, (struct sockaddr*)&the_addr, &addr_size);
   while (1) {
     recv(newfd, r_buff, sizeof r_buff, 0);
     printf("\n[client] %s", r_buff);

     if (strcmp(r_buff, "exit") == 0)
         break;

     printf("\nserver: ");
     fgets(r_buff, sizeof r_buff, stdin);

     send(newfd, s_buff, sizeof s_buff, 0);
     if (strcmp(r_buff, "exit") == 0)
         break;
     printf("\n");
   }

   close(newfd);
   close(sockfd);
    return 0;
}
