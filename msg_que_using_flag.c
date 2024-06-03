/*
 IPC message queue creation with flag IPC_CREAT and IPC_EXCL.
*/

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int msgid; /*specified or received msg queue id */
  key_t key=11; /* key for msgget() */
  msgid=msgget(key,IPC_CREAT|IPC_EXCL);
  if(msgid<0) {
    perror("Message failed");
    exit(1);
  }
  else {
    printf("Message queue is created with key value %d",msgid);
  }
}