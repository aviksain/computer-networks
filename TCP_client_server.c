
/*
  Design TCP iterative client and server application to reverse the given input sentence.
*/


// Client:-
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#define MAXLINE 20
#define SERV_PORT 5777

main(int argc,char *argv) {
  char sendline[MAXLINE],revline[MAXLINE];
  int sockfd;
  struct sockaddr_in servaddr;
  
  sockfd=socket(AF_INET,SOCK_STREAM,0);
  bzero(&servaddr,sizeof(servaddr));
  servaddr.sin_family=AF_INET;
  servaddr.sin_port=ntohs(SERV_PORT);
  connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
  printf("\nEnter the data to be send");

  while(fgets(sendline,MAXLINE,stdin)!=NULL) {
    write(sockfd,sendline,strlen(sendline));
    printf("\nline send");
    read(sockfd,revline,MAXLINE);
    printf("\n Reverse of the given sentence is:%s",revline);
    printf("\n");
  }

  exit(0);
}




// Server:-

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#define MAXLINE 20
#define SERV_PORT 5777


main(int argc,char *argv) {
  int i,j;
  ssize_t n;
  char line[MAXLINE],revline[MAXLINE];
  int listenfd,connfd,clilen;
  struct sockaddr_in servaddr,cliaddr;

  listenfd=socket(AF_INET,SOCK_STREAM,0);
  bzero(&servaddr,sizeof(servaddr));
  servaddr.sin_family=AF_INET;
  servaddr.sin_port=ntohs(SERV_PORT);
  bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
  listen(listenfd,1);
  
  for(;;) {
    clilen=sizeof(cliaddr);
    connfd=accept(listenfd,(struct
    sockaddr*)&cliaddr,&clilen);
    printf("connect to client");

    while(1) {
      if((n=read(connfd,line,MAXLINE))==0) break;

      line[n-1]='\0';
      j=0;
      
      for(i=n-2; i>=0; i--) revline[j++]=line[i];

      revline[j]='\0';
      write(connfd,revline,n);
    }

  }
}
