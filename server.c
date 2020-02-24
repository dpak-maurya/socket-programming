#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/ipc.h>

int main()
{
    int sfd,nsfd;
    struct sockaddr_in addr,cli;
    unsigned int len;
    char mesg[]="Hii, Welcome to World of Socket Programming\n";

    if((sfd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    addr.sin_family=AF_INET;
    addr.sin_port=htons(10000);
    addr.sin_addr.s_addr=INADDR_ANY;
    bzero(&addr.sin_zero,8);

    len=sizeof(struct sockaddr_in);
    
    if(bind(sfd,(struct sockaddr*)&addr,len)==-1)
    {
    	perror("bind failed\n");
    	exit(EXIT_FAILURE);
    }

    if(listen(sfd,5)==-1)
    {
    	perror("listening failed\n");
    	exit(EXIT_FAILURE);
    }
    while(1){
    	if((nsfd=accept(sfd,(struct sockaddr*)&cli,&len))==-1)
    	{
    		perror("accept\n");
    		exit(EXIT_FAILURE);
    	}
    	// char buff[100];
    	// recv(nsfd,buff,sizeof(buff),0);
    	// printf("%s\n",buff );
    	int sent=send(nsfd,mesg,strlen(mesg),0);
    	printf("Sent %d bytes to client :%s\n", sent,inet_ntoa(cli.sin_addr));
    	close(nsfd);
    }
 	return 0;
}

