/*
============================================================================
Name : 20s.c
Author : Chandanala Vishwateja
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 15th Oct, 2023.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
int res,n;
res=open("fifo1",O_WRONLY);
write(res,"murli sending the message", 26);
printf("sender pid is %d\n",getpid());
}
