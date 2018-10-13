
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


/*
NOTICE:-
sometimes , first time client will not so close 1st time then again run.
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

int main(int argc,char *argv[]) 
{
	const char* server_name = "localhost";
	const int server_port =8801;
	struct sockaddr_in server_address;
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;


		server_address.sin_port = htons(server_port);
		server_address.sin_addr.s_addr=inet_addr(argv[1]);
		int sock;

	if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
	 {
		pf("could not create socket\n");
		return 1;
	 }
		
		char data_to_send[1000];
		if(strlen(argv[2])>32)
		{
		pf("\nerror : size exceed\n");
		return 0;

		}

		int len=sendto(sock, argv[2], strlen(argv[2]), 0,(struct sockaddr*)&server_address, sizeof(server_address));

		char buffer[100];
		recvfrom(sock, buffer, len, 0, NULL, NULL);

		buffer[len] = '\0';
		pf("recieved: %s\n", buffer);

		close(sock);

		return 0;
}

