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
#include<time.h>
#define pf printf
#define sf scanf

int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		pf("Format of command line argument should be: Use (ip) (port)\n");
		return 0;
	}
  	int csock,noofbytes; //variable for client socket and number of bytes
 
  	struct sockaddr_in serverAddr, clad;
  	socklen_t addr_size;

  	csock = socket(PF_INET, SOCK_DGRAM, 0);

  	//Initializing server information
  	serverAddr.sin_family = AF_INET;
  	serverAddr.sin_port = htons(atoi(argv[2]));
  	serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
  
  	//Initializing client information
  	clad.sin_family = AF_INET;
  	clad.sin_port = htons(7892);
  	clad.sin_addr.s_addr = htonl(INADDR_ANY);
  
  	bind(csock,(struct sockaddr *) &clad, sizeof(clad));

  	addr_size = sizeof(serverAddr);
    
  	char a[100]="Tell the time!";
  	noofbytes = strlen(a) + 1;
  	
  	pf("Establishing connection to server.\n");
	sendto(csock, a, noofbytes, 0, (struct sockaddr *) &serverAddr, sizeof(serverAddr));  //Sending data
 	
 	pf("Connected to server.\n");
	
	recvfrom(csock, a,100, 0, (struct sockaddr *) &serverAddr, &addr_size);
  	pf("Received from server: %s\n",a);   
  	
  	return 0;
}

