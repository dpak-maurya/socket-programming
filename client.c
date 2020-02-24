#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
    int sfd;
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(10000);
    addr.sin_addr.s_addr=INADDR_ANY;
    bzero(&addr,sizeof(addr));

    if((sfd=socket(AF_INET,SOCK_STREAM,0))==-1)
    printf("socket creation failed\n");
    
    int len=sizeof(struct sockaddr_in);
    if(bind(sfd,(struct sockaddr*)&addr,len)==-1)
    {
        printf("bind failed\n");
        exit(-1);
    }

    connect(sfd,(struct sockaddr*)&addr, sizeof(addr));
     char mesg[]="I am the client";
     char buff[100];
     recv(sfd,buff,100,0);
     if(buff)
     printf("%d\n", strlen(buff));
      //send(sfd,mesg,strlen(mesg),0);

    return 0;
}