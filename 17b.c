/*
============================================================================
Name : 17b.c
Author : Chandanala Vishwateja
Description : Write a program to execute ls -l | wc.
b. use dup2
Date: 15th Oct, 2023.
============================================================================
*/

#include <stdlib.h>
#include <fcntl.h>
#include<errno.h>
#include<sys/wait.h>
#include <unistd.h>
#include<stdio.h>
int main(){
    int a[2];
  pipe(a);
   if(!fork())
    {
          // close(1);
             dup2(a[1],1);
           close(a[0]);
           execlp("ls","ls","-l",NULL);
    }
    else
    {
        // close(0);
          dup2(a[0],0);
           close(a[1]);
           execlp("wc","wc",NULL);
    }

}
