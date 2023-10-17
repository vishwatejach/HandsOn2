/*
============================================================================
Name : 33c.c
Author : Chandanala Vishwateja
Description : Write a program to communicate between two machines using socket.
Date: 15th Oct, 2023.
============================================================================
*/




#include <sys/types.h>  
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdio.h>   
#include <unistd.h>     


void main()
{
    int sfd; 
    int cs;        

    struct sockaddr_in address; 

    ssize_t rb, wb; 
    char dataFromServer[100];

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1)
    {
        perror("Error while creating socket!");
        _exit(0);
    }
    printf("Client side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8083);

    cs = connect(sfd, (struct sockaddr *)&address, sizeof(address));
    if (cs == -1)
    {
        perror("Error while connecting to server!");
        _exit(0);
    }
    printf("Client to server connection successfully established!\n");

    rb = read(sfd, dataFromServer, 100);
    if (rb == -1)
        perror("Error while reading from network via socket!");
    else
        printf("Data from server: %s\n", dataFromServer);

    wb = write(sfd, "I'm the client!", 15);
    if (wb == -1)
        perror("Error while writing to network via socket!");
    else
        printf("Data sent to server!");
    close(sfd);
}
