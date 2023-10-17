/*
============================================================================
Name : 33s.c
Author : Chandanala Vishwateja
Description :  Write a program to communicate between two machines using socket.
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
    int sfd, cfd;
    int bs; // Determines success of `bind`
    int ls; // Determines success of `listen`
    int clientSize;

    struct sockaddr_in address, client;

    ssize_t rb, wb;
    char dataFromClient[100];

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1)
    {
        perror("Error while creating socket!");
        _exit(0);
    }
    printf("Server side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8083);

    bs = bind(sfd, (struct sockaddr *)&address, sizeof(address));
    if (bs == -1)
    {
        perror("Error while binding name to socket!");
        _exit(0);
    }
    printf("Binding to socket was successful!\n");

    ls = listen(sfd, 2);
    if (ls == -1)
    {
        perror("Error while trying to listen for connections!");
        _exit(0);
    }
    printf("Now listening for connections on a socket!\n");

    clientSize = (int)sizeof(client);
    cfd = accept(sfd, (struct sockaddr *)&client, &clientSize);
    if (cfd == -1)
        perror("Error while accepting a connection!");
    else
    {

	    wb = write(cfd, "I'm the server!", 15);
        if (wb == -1)
            perror("Error while writing to network via socket!");
        else
            printf("Data sent to client!\n");

        rb = read(cfd, dataFromClient, 100);
        if (rb == -1)
            perror("Error while reading from network via socket!");
        else
            printf("Data from client: %s\n", dataFromClient);
}

    close(cfd);

    close(sfd);
}
