#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "../include/common.h"

extern struct driver_info *driver;
/**
*	Search tokinid will search the tokien id for given driver information.
 */
int search_tokenid(struct driver_info data)
{
	int i = 0;
	count_info(GET_COUNT);
	while(i++ < count)
	{
		if(!strcmp((driver + i)->name,data.name) && !strcmp((driver + i)->mom_name,data.mom_name)) 
			return (driver + i)->token_id;
	}
	return 0;
}
/**
*	Server will get the driver name & mother name 
*	Return tokenid to Client.
*/
void *serv()
{
	int sock, sock_t;
	int token_id = 0;
	struct driver_info driver_data;
	int addr_len, bytes_read;
	char recv_data[1024];
	struct hostent *host;
	struct sockaddr_in server_addr, client_addr, server_addr_t;

	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("Socket");
		exit(1);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5000);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(server_addr.sin_zero),8);


	if (bind(sock,(struct sockaddr *)&server_addr,
				sizeof(struct sockaddr)) == -1)
	{
		perror("Bind");
		exit(1);
	}

	addr_len = sizeof(struct sockaddr);

	fflush(stdout);

	{

		bytes_read = recvfrom(sock,recv_data,1024,0,
				(struct sockaddr *)&client_addr, &addr_len);


		recv_data[bytes_read] = '\0';

		memcpy(&driver_data, recv_data, bytes_read);
		token_id = search_tokenid(driver_data);
		sleep(1);

		if(bytes_read> 0) {
			host= (struct hostent *) gethostbyname((char *)"127.0.0.1");
			if ((sock_t = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
			{
				perror("socket");
				exit(1);
			}
			server_addr_t.sin_family = AF_INET;
			server_addr_t.sin_port = htons(5002);
			server_addr_t.sin_addr = *((struct in_addr *)host->h_addr);
			bzero(&(server_addr_t.sin_zero),8);


			sendto(sock_t, &token_id, 4, 0,(struct sockaddr *)&server_addr_t, sizeof(struct sockaddr));

		}

		close(sock);
		fflush(stdout);

	}
}
