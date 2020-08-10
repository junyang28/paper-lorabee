
// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <string.h> 
#include <unistd.h>
#define PORT 8080 
   
int main(int argc, char const *argv[]) 
{ 
    struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char hello[] = "Hello from client"; 
    //while(1){
    //if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    if ((sock = socket(AF_INET, SOCK_DGRAM,  0)) < 0)
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
    
    //serv_addr.sin_addr.s_addr = inet_addr("10.42.0.55");
    //serv_addr.sin_addr.s_addr = inet_addr("192.168.0.104");
   
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
 	/*   
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
  	*/ 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    }
    

    char command[100]; 
    command[0] = *argv[1];
    command[1] = *(argv[1]+1);
    command[2] = '\0';
    printf("send %s\n",command);
	//    scanf("%s",command);
	//send(sock, command,strlen(command),0);
	//
	 sendto(sock , command , strlen(command) , MSG_CONFIRM,  (struct sockaddr *)&serv_addr, sizeof(serv_addr)); 
	   // send(sock , command , strlen(command) , 0 ); 
	    //send(sock , command , strlen(command) , 0 ); 
	    //printf("Hello message sent\n"); 
	    //valread = read( sock , buffer, 1024); 
	    //printf("%s\n",buffer ); 
	close(sock);
   //}
    return 0; 
} 
