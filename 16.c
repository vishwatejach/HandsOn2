/*
============================================================================
Name : 16.c
Author : Chandanala Vishwateja
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 15th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
int fd1[2],fd2[2],n,m;
char buffer[100];
pid_t p;
pipe(fd1);
pipe(fd2);
p=fork();

if(p>0){//parent process
	close(fd1[0]);
	close(fd2[1]);
	printf("passing value to chlid--> pipe1\n");
	write(fd1[1],"hello my chlid\n", 15);
	m=read(fd2[0],buffer,100);
	write(1,buffer,m);
	wait(NULL);
}
else{
close(fd1[1]);
close(fd2[0]);
n=read(fd1[0],buffer,n);
write(1,buffer,n);
printf("passing value to parent -->pipe2\n");
write(fd2[1],"hello my parent\n",15);
wait(NULL);
}


return 0;
}
