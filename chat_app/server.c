//TCP server side program

#include"header.h"
#define size 100


void *send_data(void *nfd)
{
	char s[size];
	while(1)
	{
		printf("\033[33myou	: \033[0m%s\n",s);
		scanf(" %[^\n]",s);
		write(*(int*)nfd,s,strlen(s)+1);

		if(strcmp(s,"bye")==0)
			return 0;	
	}
}

void *receive_data(void *nfd)
{
	char s[size];
	while(1)
	{
		read(*(int*)nfd,s,sizeof(s));
		printf("\033[31mclient	: \033[0m%s\n",s);

		if(strcmp(s,"bye")==0)
			return 0;
	}
}

int main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("usage : ./server portno ipaddr\n");
		return 0;
	}

	int fd, len, nfd;
	char s[size];

	fd = socket(AF_INET,SOCK_STREAM,0);
	
	if(fd<0)
	{
		perror("socket");
		return 0;
	}

	//perror("socket");
	
	struct sockaddr_in serv_id, client_id; 
	
	serv_id.sin_family = AF_INET;
	serv_id.sin_port = htons(atoi(argv[1]));
	serv_id.sin_addr.s_addr = inet_addr(argv[2]);
	
	len = sizeof(serv_id);
	
	if(bind(fd,(struct sockaddr*)&serv_id,len)<0)
	{
		perror("bind");
		return 0;
	}

	//perror("bind");
	
	if(listen(fd,5)<0)
	{
		perror("listen");
		return 0;
	}
	//perror("listen");
	
	printf("\033[35;5mWaiting for connection...\033[25m\n");
	nfd = accept(fd,(struct sockaddr*)&client_id,&len);

	if(nfd<0)
	{
		perror("accept");
		close(fd);
		return 0;
	}
	system("clear");
	printf("---------------------------\n");
	printf("\033[32;92mConnected.\nIp address : %s\033[0m\n",inet_ntoa(client_id.sin_addr));
	printf("---------------------------\n");

	
	pthread_t sender,receive;
	
	if(pthread_create(&sender,NULL,send_data,&nfd)!=0)
	{
		perror("pthread_create");
		return 0;
	}
	if(pthread_create(&receive,NULL,receive_data,&nfd)!=0)
	{
		perror("pthread_create");
		return 0;
	}
	
	pthread_join(sender,NULL);
	pthread_join(receive,NULL);
	
	printf("---------------------------\n");
	close(nfd);
	close(fd);
	
	return 0;
}
