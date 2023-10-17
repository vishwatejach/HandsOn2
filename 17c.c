/*
============================================================================
Name : 17c.c
Author : Chandanala Vishwateja
Description : Write a program to execute ls -l | wc.
c. use fcntl
Date: 15th Oct, 2023.
============================================================================
*/

#include <unistd.h>    
#include <sys/types.h> 
#include <fcntl.h>     
#include <stdio.h>     

void main()
{
    
    int fd[2];  
    int ps; 
    pid_t cpid;

    ps = pipe(fd);

    if (ps == -1)
        perror("Error while creating the file!");
    else
    {
        cpid = fork();

        if (cpid == -1)
            perror("Error while forking child!");
        else if (cpid == 0)
        {
            
            close(STDIN_FILENO);
            fcntl(fd[0], F_DUPFD, STDIN_FILENO); 
            close(fd[1]);
            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            // Parent will enter this branch
            close(STDOUT_FILENO);
            fcntl(fd[1], F_DUPFD, STDOUT_FILENO); 
            close(fd[0]);
            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
}
