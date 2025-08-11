//TCP client side program

#include"header.h"
#define size 100


void *send_data(void *fd)
{
	char s[size];
	while(1)
	{
		printf("\033[33myou 	: \033[0m%s\n",s);
		scanf(" %[^\n]",s);
		write(*(int*)fd,s,strlen(s)+1);

		if(strcmp(s,"bye")==0)
			return 0;
	}
}

void *receive_data(void *fd)
{
	char s[size];
	while(1)
	{
		read(*(int*)fd,s,sizeof(s));
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

	int fd, len;
	
	fd = socket(AF_INET,SOCK_STREAM,0);
	
	if(fd<0)
	{
		perror("socket");
		return 0;
	}
	//perror("socket");
	
	struct sockaddr_in server_id;
	
	server_id.sin_family = AF_INET;
	server_id.sin_port   = htons(atoi(argv[1]));
	server_id.sin_addr.s_addr = inet_addr(argv[2]);
	
	len = sizeof(server_id);
	
	if(connect(fd,(struct sockaddr*)&server_id,len)<0)
	{
		perror("connect");
		return 0;
	}
	system("clear");
	printf("---------------------------\n");
	printf("\033[32;92mConnected.\033[0m\n");
	printf("---------------------------\n");
	
	pthread_t sender,receive;

	if(pthread_create(&sender,NULL,send_data,&fd)!=0)
	{
		perror("pthread_create");
		return 0;
	}
	if(pthread_create(&receive,NULL,receive_data,&fd)!=0)
	{
		perror("pthread_create");
		return 0;
	}

	pthread_join(sender,NULL);
	pthread_join(receive,NULL);

	printf("---------------------------\n");
	
	close(fd);
	
	return 0;
}
