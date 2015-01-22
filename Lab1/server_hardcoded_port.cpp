#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#define SA struct sockaddr
#define LISTENQ 5

long count_characters(FILE *f) 
{
    fseek(f, -1L, 2);
    long last_pos = ftell(f); // returns the position of the last element of the file
    last_pos++;
    return last_pos;
}


int main(int argc,char**argv)
{
int fd,sockfd,listenfd,connfd;
pid_t childpid;
socklen_t client;

struct sockaddr_in servaddr,cliaddr;

listenfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));

servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(atoi(argv[1]));

bind(listenfd,(SA*)&servaddr,sizeof(servaddr));

listen(listenfd,LISTENQ);
client=sizeof(cliaddr);
connfd=accept(listenfd,(SA*)&cliaddr,&client);
char buffer[1000];
FILE *fp;
read(connfd,buffer,100);
//system("whoami");

fp=fopen("inter.txt","w");
fprintf(fp,"%s",buffer);

FILE *fp1, *fp2;

printf("the file was received successfully.\n");
/*
if(fp1 = fopen("inter.txt", "r"))    
    {
      int cnt;
      char ch;
        fp2 = fopen("Res.txt", "w");
        cnt = count_characters(fp1); // to count the total number of characters inside the source file
        fseek(fp1, cnt-2, SEEK_SET);     // makes the pointer fp1 to point at the last character of the file
 
        while (cnt)
        {
            ch = fgetc(fp1);
            fputc(ch, fp2);
            fseek(fp1, cnt-2, SEEK_SET);     // shifts the pointer to the previous character
            cnt--;
        }
        printf("\n**File copied successfully in reverse order**\n");
    }



printf("the new file created is Rev.txt.\n");
*/


}
 
