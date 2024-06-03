/*
  Write a program to send a text message from one terminal to another terminal via IPC message queue.
  (Hints: Create a message queue using msgget() function send & receive using Msgsnd(),msgrcv().)
*/



// Receive message:-

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main() { 
  struct msgbht {
    long mtype;
    char mtext[100];
  }send,recv;

  int msg,len;
  msg=msgget((key_t)25,IPC_CREAT|0666);
  
  if(msg<0) {
    perror("Message failed");
    exit(1);
  }

  strcpy(send.mtext,"i am fine thank you!");
  send.mtype=2;
  len=strlen(send.mtext);
  
  if(msgrcv(msg,&recv,100,1,0)==-1) {
    perror("Message failed");
    exit(1);
  }

  if(msgsnd(msg,&send,len,0)==-1) {
    perror("Message failed");
    exit(1);
  }

  printf("Message from program 1 is : \n%s\n",recv.mtext);
}





// Send message:-

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
  struct msgbht
  {
    long mtype;
    char mtext[100];
  }send,recv;
  
  int msg,len;
  msg=msgget((key_t)25,IPC_CREAT|0666);
  
  if(msg<0) {
    perror("Message failed");
    exit(1);
  }

  strcpy(send.mtext,"Hello,How are you?");
  send.mtype=1;
  len=strlen(send.mtext);

  if(msgsnd(msg,&send,len,0)==-1) {
    perror("Message failed");
    exit(1);
  }

  if(msgrcv(msg,&recv,100,2,0)==-1) {
    perror("Message failes");
    exit(1);
  }

  printf("Message from program 2 is : \n%s\n",recv.mtext);
}
