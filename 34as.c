/*
============================================================================
Name : 34as.c
Author : Chandanala Vishwateja
Description :Write a program to create a concurrent server.
a. use fork
Date: 15th Oct, 2023.
============================================================================
*/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
 

#define PORT 4444
 
int main()
{
 
    int sockfd, ret;
 
    
    struct sockaddr_in serverAddr;
 
  
    int clientSocket;
 
 
    struct sockaddr_in cliAddr;
 

    socklen_t addr_size;
 

    pid_t childpid;
 
  
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
 
    
    if (sockfd < 0) {
        printf("Error in connection.\n");
        exit(1);
    }
 
    printf("Server Socket is created.\n");
 
    
    memset(&serverAddr, '\0',
           sizeof(serverAddr));
 

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
 
    
    serverAddr.sin_addr.s_addr
        = inet_addr("127.0.0.1");
 
   
    ret = bind(sockfd,
               (struct sockaddr*)&serverAddr,
               sizeof(serverAddr));
 

    if (ret < 0) {
        printf("Error in binding.\n");
        exit(1);
    }
 
    
    if (listen(sockfd, 10) == 0) {
        printf("Listening...\n\n");
    }
 
    int cnt = 0;
    while (1) {
 
       
        clientSocket = accept(
            sockfd, (struct sockaddr*)&cliAddr,
            &addr_size);
 
   
        if (clientSocket < 0) {
            exit(1);
        }
 
      
        printf("Connection accepted from %s:%d\n",
               inet_ntoa(cliAddr.sin_addr),
               ntohs(cliAddr.sin_port));
 
        printf("Clients connected: %d\n\n",
               ++cnt);
 
        if ((childpid = fork()) == 0) {
 
          
            close(sockfd);
 
         
   
            send(clientSocket, "hi client",
                 strlen("hi client"), 0);
        }
    }

    close(clientSocket);
    return 0;
}
