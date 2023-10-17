/*
============================================================================
Name : 27b.c
Author : Chandanala Vishwateja
Description : Write a program to receive messages from the message queue.
b. with IPC_NOWAIT as a flag
Date: 15th Oct, 2023.
============================================================================
*/

#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

struct my_msg{
long int msg_type;
char some_text[BUFSIZ];
};

int main(){
int running=1;
int msgid;
struct my_msg some_data;
long int msg_to_rec=0;
msgid=msgget((key_t)12345,0666|IPC_CREAT);

while(running){
msgrcv(msgid,(void *)&some_data,BUFSIZ,msg_to_rec,IPC_NOWAIT);
printf("data recieved %s\n",some_data.some_text);

if(strncmp(some_data.some_text,"end",3)==0){running=0;}
}
msgctl(msgid,IPC_RMID,0);
}
