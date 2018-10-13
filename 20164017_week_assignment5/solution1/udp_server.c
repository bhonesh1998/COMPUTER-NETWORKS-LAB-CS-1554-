/*
***********************************************************
***********************************************************
 
NAME-BHONESH CHAWLA
REGNO-20164017
BATCH-CS-1
CONTACT-+918619127663
EMAIL-rajachawla778@gmail.com
***********************************************************
***********************************************************
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<math.h>
#define pf printf
#define sf scanf

int main() 
{
		
		int SERVER_PORT = 8801;

		struct sockaddr_in server_address;memset(&server_address,0,sizeof(server_address));
		
		server_address.sin_family=AF_INET;

		server_address.sin_port=htons(SERVER_PORT);

		server_address.sin_addr.s_addr=htonl(INADDR_ANY);

		int sock;
			if ((sock=socket(PF_INET,SOCK_DGRAM,0)) < 0) 
			{
				pf("could not create socket\n");
				return 1;
			}

		if ((bind(sock,(struct sockaddr *)&server_address,sizeof(server_address))) < 0) 
			{
				pf("could not bind socket\n");
				return 1;
			}

		pf("\nserver started waiting for connnection\\n");
		struct sockaddr_in client_address;
			int client_address_len = 0;

		while (1) 
			{
			char buffer[500];
			int len=recvfrom(sock, buffer, sizeof(buffer), 0,(struct sockaddr *)&client_address,&client_address_len);

			buffer[len] = '\0';
			pf("received: %s \n", buffer);
		sendto(sock, buffer, len, 0, (struct sockaddr *)&client_address,sizeof(client_address));
			}
	

	return 0;
}

