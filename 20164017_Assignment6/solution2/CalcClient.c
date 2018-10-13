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
int main(int argc,char *argv[])
{
	if(argc!=3)
		{
			pf("you should give arguments like this : [hostname] [port]\n");
			return 0;
		}

		int clisoc, portno, nBytes,sv;

		char buff[1024];

		struct sockaddr_in serverAddr, clad;

		socklen_t addr_size;

		clisoc = socket(PF_INET, SOCK_STREAM, 0);

		portno = atoi(argv[2]);

		struct hostent *he;
		struct in_addr **ad;
		if ( (he = gethostbyname( argv[1] ) ) == NULL) 
		{
		    herror("Error");
		    return 1;
		}
		ad=(struct in_addr **) he->h_addr_list;
		char ip[100];
		strcpy(ip,inet_ntoa(*ad[0]));

		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(portno);
		serverAddr.sin_addr.s_addr = inet_addr(ip);



		addr_size = sizeof serverAddr;

		if(connect(clisoc, (struct sockaddr *) &serverAddr, addr_size)<0)
			{ 
				pf("connection error\n");
				return 0;
			}
		else
		pf("Connected to %s:%d \n",ip,portno);

		pf("enter an expression like this: \n Operand1 Operator(+ - * / ^) Operand2: ");

		fgets(buff,1024,stdin);

		char a[50];

		pf("You typed: %s",buff);

		nBytes = strlen(buff) + 1;


		send(clisoc,buff,nBytes,0);

		recv(clisoc, a, 1024, 0);

		pf("Received from server: %s \n",a);   

		close(clisoc);
		return 0;
}

