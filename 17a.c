/*
============================================================================
Name : 17a.c
Author : Chandanala Vishwateja
Description : Write a program to execute ls -l | wc.
a. use dup
Date: 15th Oct, 2023.
============================================================================
*/




#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include<errno.h>
#include<sys/wait.h>
#include <unistd.h>
int main(){    
    int a[2];
  pipe(a);
   if(!fork())
    {
           close(2);
             dup(a[1]);
           close(a[0]);
           execlp("ls","ls","-l",NULL);
    }
    else
    {
         close(0);
          dup(a[0]);
           close(a[1]);
           execlp("wc","wc",NULL);
    }
}
