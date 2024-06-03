/* 
  Create a message queue with message get (msgget()) function & IPC_CREAT.Also show the perror function that when message queue creation fails it will generation an error.
*/

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

main() {
  int msgid; /*return value from msgget()*/
  key_t key;/*key to be passed to msgget()*/
  int mykey;
  msgid=msgget((key)|mykey, IPC_CREAT|0);
  printf("Message queue is created with key value %d",msgid);
}