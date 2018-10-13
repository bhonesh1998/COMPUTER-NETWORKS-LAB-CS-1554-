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
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include<ctype.h>

int calc(char str[])
{
int i; int len=strlen(str);
int sum=0;

for(i=0;i<len;i++)
{
int k=str[i]-'0';
sum=sum+k;
} 
return sum;
}

int main(int argc,char * argv[])
{
if(argc!=2)
{
printf("\nuse {port}\n");
return 1;
}


struct sockaddr_in server_address;
//memset(&server_address,0,sizeof(server_address));
server_address.sin_family=AF_INET;
server_address.sin_port=htons(atoi(argv[1]));
server_address.sin_addr.s_addr=htonl(INADDR_ANY);

int sock;
if((sock=socket(PF_INET,SOCK_DGRAM,0))<0)
{
printf("could not create socket\n");
return 1;
}

if((bind(sock,(struct sockaddr *)&server_address,sizeof(server_address)))<0)
{
printf("could not bind socket\n");
return 1;
}

printf("\nserver started waiting for connnection\\n");
struct sockaddr_in client_address;
int client_address_len = 0;
int g=0;

while(1)
{

char buffer[1001];

int len=recvfrom(sock,buffer,1000,0,(struct sockaddr *)&client_address,&client_address_len);
buffer[len] = '\0';

printf("\nreceived:%s\n",buffer);

if(g!=0)
{
char err[]="Sorry,Cannot Compute!";
int i;
for(i=strlen(buffer)-1;i>=0;i--)
{
if(isdigit(buffer[i])==0)
{
sendto(sock,err,strlen(err),0,(struct sockaddr *)&client_address,sizeof(client_address));
close(sock);
return 0;
}

} 

while(1){

int ans=calc(buffer);
sprintf(buffer,"%d",ans);

sendto(sock,buffer,strlen(buffer),0,(struct sockaddr *)&client_address,sizeof(client_address));

if(ans<10)
{
close(sock);
return 0;
}

}

}
g++;
}

printf("\n");
close(sock);
return 0;
}
