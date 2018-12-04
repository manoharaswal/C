#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "../include/common.h"

int tokenid = 0;
extern struct entry_system **car_sys;
extern struct driver_info *driver;

/**
*	This function is client as well as server , get driver info and retrive token number from the server function.
*/
void *client()
{
	int sock, sock_r;
	int addr_len, bytes_read;
	char recv_data[1024];
	struct driver_info driver_data;
	struct sockaddr_in server_addr, client_addr, server_addr_r;
	struct hostent *host;
	char send_data[1024];
	/*
	*	DRIVER INFORMATION
	*/
	printf("Enter Driver NAME");
	scanf("%s",driver_data.name);
	printf("Enter Drivers mother NAME:");
	scanf("%s",driver_data.mom_name);

	host= (struct hostent *) gethostbyname((char *)"127.0.0.1");
	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5000);
	server_addr.sin_addr = *((struct in_addr *)host->h_addr);
	bzero(&(server_addr.sin_zero),8);
	memcpy(send_data, &driver_data,sizeof(driver_data));
	sendto(sock, send_data, sizeof(driver_data), 0,(struct sockaddr *)&server_addr, sizeof(struct sockaddr));
	if ((sock_r = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("Socket");
		exit(1);
	}

	server_addr_r.sin_family = AF_INET;
	server_addr_r.sin_port = htons(5002);
	server_addr_r.sin_addr.s_addr = INADDR_ANY;
	bzero(&(server_addr_r.sin_zero),8);


	if (bind(sock_r,(struct sockaddr *)&server_addr_r,
				sizeof(struct sockaddr)) == -1)
	{
		perror("Bind");
		exit(1);
	}

	addr_len = sizeof(struct sockaddr);

	bytes_read = recvfrom(sock_r,recv_data,1024,0,(struct sockaddr *)&client_addr, &addr_len);
	recv_data[bytes_read] = '\0';
	memcpy(&tokenid, recv_data, 4);
	printf("\nTokenid is %d", tokenid );
	if(bytes_read > 0)
		close(sock_r);
	fflush(stdout);
}
