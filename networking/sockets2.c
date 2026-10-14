#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char **argv){
    struct addrinfo *p, *listp, hints;
    char buf[8000];
    int a,flags;

    if(argc!=2){
        fprintf(stderr,"Please provide correct number of arguments:2\n");
        exit(0);
    }

    memset(&hints,0,sizeof(hints));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;


    //todo try adding service instead of null and see the returns
    if((a=getaddrinfo(argv[1],NULL,&hints,&listp))!=0){
        fprintf(stderr,"getaddrinfo returned error!");
        exit(0);
    }

    flags = NI_NUMERICHOST;

    for(p=listp; p ;p = p->ai_next){
        //getnameinfo(p->ai_addr,p->ai_addrlen,buf,8000,NULL,0,flags);
        struct sockaddr_in *saddr = (struct sockaddr_in *)p->ai_addr;
        inet_ntop(AF_INET,&(saddr->sin_addr),buf,8000);
        printf("%s\n",buf);
    }

    exit(0);

}