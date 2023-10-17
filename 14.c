/*
============================================================================
Name : 14.c
Author : Chandanala Vishwateja
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 15th Oct, 2023.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
int fd[2],n;
char buffer[100];
char buffer1[100];
pid_t p;
pipe(fd);
p=fork();

if(p>0){//parent process
printf("passing value to chlid\n");
read(0,buffer1,10);
write(fd[1],buffer1,6);
}

else{ //chlid process
      printf("chlid received data\n");
      n=read(fd[0],buffer,100);
      write(1,buffer,n);

}

return 0;

}

