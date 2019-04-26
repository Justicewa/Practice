#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#define BUF_SIZE 100

int main(){
	//socket
	int iClient = socket(AF_INET,SOCK_STREAM,0);
	if(iClient == -1){
		printf("Create socket failed!\n");
		return -1;
	}
	printf("Create socket success\n");

	//connect
	struct sockaddr_in stServer;
	stServer.sin_family = AF_INET;
	stServer.sin_port = htons(8888);
	stServer.sin_addr.s_addr= inet_addr("127.0.0.1");
	int ret = connect(iClient,(struct sockaddr*)&stServer,sizeof(struct sockaddr));
	if(ret == -1){
		return -1;
	}
	printf("connect success\n");

	//send
	char buf[BUF_SIZE]={0};
	gets(buf);
	ret = send(iClient,buf,BUF_SIZE,0);
	if(ret == -1){
		printf("send failed\n");
	}
	printf("send :%d\n",ret);

	//recv
	memset(buf,0,BUF_SIZE);
	ret = recv(iClient,buf,BUF_SIZE,0);
	if(ret <= 0){
		printf("recv failed\n");
	}
	printf("recv:%s\n",buf);
	close(iClient);

	return 0;
}
