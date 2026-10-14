#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>




int main(int argc, char **argv){
    open_clientfd(argv[1],argv[2]);
}
int open_clientfd(char *host,char *port){

    struct addrinfo hints,*listp,*p;
    int val,flags;
    int clientfd;


    memset(&hints,0,sizeof(struct addrinfo));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if((val = (getaddrinfo(host,NULL,&hints,&listp)))!= 0){
        fprintf(stderr,"Getaddrinfo returned err!\n");
    };



    for(p = listp;p;p = p->ai_next){
        if((clientfd = socket(p->ai_family,p->ai_socktype,p->ai_protocol))<0){
            continue;
        }

        if((connect(clientfd,p->ai_addr,p->ai_addrlen))!= -1){
            printf("Connection successful\n"); 
            return clientfd;
            
        }

        close(clientfd);
    } 
        freeaddrinfo(listp);

        if(!p){ //All connects failed
            printf("Connection failed\n");
            return -1;
        }
}