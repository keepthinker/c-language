#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include <netinet/in.h>
#include <strings.h>
#include<string.h>
#define LISTENQ 1024
#define MAXLINE 10

int open_listenfd(int port);
void printf_carr_int(char *arr, int len);

int main(int argc, char **argv)
{
  printf("server is starting\n");
  int listenfd, connfd, port, clientlen;
  struct sockaddr_in clientaddr;// = malloc(sizeof (struct sockaddr_in));
  struct hostent *hp;
  char *haddrp;
  
  if(argc != 2)
  {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
  }
  port = atoi(argv[1]);

  listenfd = open_listenfd(port);
  printf("open listen fd:%d\n", listenfd);
 
  int read_size;
  char client_message[100];

  while(1) {
    int clientlen = sizeof(clientaddr);
    printf("wait a connection|clientlen: %d\n", clientlen);
    int connfd = accept(listenfd, (struct sockaddr*) &clientaddr, &clientlen);
    printf("accept a connection fd: %d\n", connfd);
    hp = gethostbyaddr((const char*)&clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    printf("after get host\n");
    printf("server connected to %s\n", hp->h_name);

    while( (read_size = recv(connfd, client_message , 2000 , 0)) > 0 )
    {   
        write(connfd, client_message , strlen(client_message));
        printf("ascii decimal: ");
        printf_carr_int(client_message, read_size);
        //relace '\n' with '\0'
        client_message[read_size -2] = 0;  //for telnet
        printf("\nhuman readable response: %s, actual size: %d\n", client_message, read_size);
    }
    printf("close connfd: %d", connfd);
    close(connfd);
  }
}

void printf_carr_int(char *arr, int len)
{
   int i;
   for(i = 0; i < len; i++) {
     printf("%d ", (int)arr[i]);
   }
   putc(10, stdout);
}

int open_listenfd(int port)
{
  int listenfd;
  int optval;
  struct sockaddr_in serveraddr;
  
  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  
  optval = 1;
  setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
  
  bzero((char*) &serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons((unsigned short)port);
  bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
  
  listen(listenfd, LISTENQ);

  return listenfd;

}
