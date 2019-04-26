#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#define BUF_SIZE 100 

int main(){
	//socket
	int iServer = socket(AF_INET,SOCK_STREAM,0);
	if(iServer == -1){
		printf("Create socket failed!\n");
		return -1;
	}
	printf("Create socket success! iServer is %d\n",iServer);
	
	//bind ip  xieyiyu duankouhao
	struct sockaddr_in stServer;
	stServer.sin_family = AF_INET;
	stServer.sin_port = htons(8888);
	stServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	int ret = bind(iServer,(struct sockaddr*)&stServer,sizeof(struct sockaddr));
	if(ret == -1){
		return -1;
	}
	printf("bind ok!\n");

	//listen
	ret =listen(iServer,5);
	if(ret == -1){
		printf("listen failed\n");
		return -1;
	}
	printf("listen success\n");

	//accep
	struct sockaddr_in stClient;
	socklen_t len = sizeof(struct sockaddr_in);
	char buf[BUF_SIZE];

	while(1){
		memset(buf,0,BUF_SIZE);
		memset(&stClient,0,len);
		int iClient = accept(iServer,(struct sockaddr*)&stClient,&len);
		if(iClient == -1){
			continue;
		}
		printf("accept success\n");
		
		//recv
		ret = recv(iClient,buf,BUF_SIZE,0);
		if(ret <= 0){
			close(iClient);
			continue;
		}
		printf("recieve : %s\n",buf);

		//send
		ret = send(iClient,buf,BUF_SIZE,0);
		printf("ret = %d\nsend:%s\n",ret,buf);
		close(iClient);

	}
	return 0;
}
