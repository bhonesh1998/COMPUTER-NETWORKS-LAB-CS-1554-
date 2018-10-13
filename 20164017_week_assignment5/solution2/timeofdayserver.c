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
	if(argc!=2)
	{
		pf("Format of command line argument should be: Use (port)\n");
		return 0;
	}
	
	struct sockaddr_in addrport;
	int sockid=socket(PF_INET, SOCK_DGRAM, 0);  //Socket descriptor
	
	if(sockid<0)
	{
		pf("Error in creating Socket.\n"); 
		return 0;
	}

	//Initializing information
	addrport.sin_family = AF_INET;
	addrport.sin_port = htons(atoi(argv[1]));
	addrport.sin_addr.s_addr = htonl(INADDR_ANY);
	
	int status= bind(sockid,(struct sockaddr *) &addrport, sizeof(addrport));  //Binding socket
	int count;
	
	time_t cur_time;
	char* ct;
	struct sockaddr_in caddr;
	char recbuff[100];
	int len=sizeof(caddr);
	recvfrom(sockid, recbuff, sizeof(recbuff), 0, (struct sockaddr *) &caddr, &len);
	
	pf("Client: %s\n",recbuff);
	cur_time=time(&cur_time);
	ct=ctime(&cur_time);
	sendto(sockid, ct, strlen(recbuff), 0, (struct sockaddr *) &caddr, sizeof(caddr));  //Sending time details to client
	
	return 0;
}

