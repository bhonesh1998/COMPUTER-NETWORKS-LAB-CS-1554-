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
	pf("you should give arguments like this: [ip] [port]\n");
	return 0;
   }
		  int clisoc, portno, nBytes,sv;

		  char buffer[1024];

		  struct sockaddr_in serverAddr, clad;

		  socklen_t addr_size;

		  clisoc = socket(PF_INET, SOCK_STREAM, 0);

		  portno = atoi(argv[2]);
		  
		  serverAddr.sin_family = AF_INET;
		  serverAddr.sin_port = htons(portno);
		  serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
		  
		  

		  addr_size = sizeof serverAddr;
		 
			if(connect(clisoc, (struct sockaddr *) &serverAddr, addr_size)<0)
			 pf("connect error\n");;
		 
		    pf("Type a sentence to send to server: ");
		    fgets(buffer,1024,stdin);
		    char a[50];
		    pf("You typed: %s",buffer);

		    nBytes = strlen(buffer) + 1;


		    send(clisoc,buffer,nBytes,0);
			 

		    close(clisoc);
            
            return 0;
}
