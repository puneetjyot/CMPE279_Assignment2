#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<errno.h>
#define PORT 8080

int main(int argc,char const*argv[]){
int new_socket,userPrivilege,valread;
char *hello;
char buffer[1024]={0};
	if(argc>1){
	new_socket=*argv[1];
	hello=argv[2];
	}
	else{
	printf("illegal arguments");
	}
	 printf("In the child\n");
    int privilegeValue= setuid(65534);
    if(privilegeValue==-1){
    printf("Unable to drop the privilege");
    exit(EXIT_FAILURE);
    }
    valread=read(new_socket,buffer,1024);
    send(new_socket,hello,strlen(hello),0);
    printf("hello message sent from child");
    return 0;
}
