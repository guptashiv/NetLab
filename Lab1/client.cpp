#include<iostream>
#include<cstdio>
#include<cstring>
#include<arpa/inet.h>
#include<cstdlib>
#include<unistd.h>
#define SA struct sockaddr

using namespace std;
int main(int argc,char**argv)
{
  
  if(argc!=3)
  {
    cout<<"Usage: port filename\n\n\n";
    return 0;
  }
int sockfd;
char fname[25];
int len;
struct sockaddr_in servaddr,cliaddr;
sockfd=socket(AF_INET,SOCK_STREAM,0);

bzero(&servaddr,sizeof(servaddr));

servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(atoi(argv[1]));

inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

connect(sockfd,(SA*)&servaddr,sizeof(servaddr));
char buffer[1000];
FILE *f;

f=fopen(argv[2],"r");
fscanf(f,"%s",buffer);
write(sockfd,buffer,1000);
printf("the file was sent successfully\n");
}
