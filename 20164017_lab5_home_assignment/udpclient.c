//in first run ,kill it and then use in second time
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

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc,char *argv[])
{

if(argc!=3)
{
printf("\nusage [ip] [port]\n");
return 1;
}

struct sockaddr_in server_address;
memset(&server_address, 0, sizeof(server_address));
server_address.sin_family = AF_INET;
server_address.sin_port = htons(atoi(argv[2]));
server_address.sin_addr.s_addr=inet_addr(argv[1]);

int sock;
if((sock=socket(PF_INET,SOCK_DGRAM,0))<0)
{
printf("could not create socket\n");
return 1;
}

char str[1001];

printf("\nenter string:");
scanf("%s",str);

int len=sendto(sock,str,strlen(str),0,(struct sockaddr*)&server_address,sizeof(server_address));

while(1)
{
char buffer[1001];
int lent=recvfrom(sock,buffer,1000,0,NULL,NULL);
buffer[lent]='\0';
char err[]="Sorry,Cannot Compute!";

printf("\nreceived string:%s",buffer);
if(strcmp(buffer,err)==0)
break;

int ans=atoi(buffer);
if(ans<10)
break;

}

close(sock);
printf("\n");
return 0;
}
