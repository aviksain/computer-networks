/*
 IPC message queue Creation with file permission.
*/

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

int main() {
  int msgid; /*return value from msgget()*/
  key_t key; /*key to be passed to msgget()*/
  int mykey;
  msgid=msgget((key)|2,IPC_CREAT|06444);
  if(msgid<0) {
    perror("Message failed");
  }
  else {
    printf("Message queue is created with key value %d",msgid);
  }
}