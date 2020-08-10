/*  
 *  ------ P2P Code Example -------- 
 *  
 *  Explanation: This example shows how to configure the module
 *  for P2P mode and the corresponding parameters. After this, 
 *  the example shows how to send packets to other radio modules
 *  which must be set with the same radio settings
 *  
 *  Copyright (C) 2015 Libelium Comunicaciones Distribuidas S.L. 
 *  http://www.libelium.com 
 *  
 *  This program is free software: you can redistribute it and/or modify  
 *  it under the terms of the GNU General Public License as published by  
 *  the Free Software Foundation, either version 3 of the License, or  
 *  (at your option) any later version.  
 *   
 *  This program is distributed in the hope that it will be useful,  
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of  
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  
 *  GNU General Public License for more details.  
 *   
 *  You should have received a copy of the GNU General Public License  
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *  
 *  Version:           0.4
 *  Design:            David Gascon
 *  Implementation:    Luismi Marti, Ruben   Martin  
 */

#include "arduPiLoRaWAN.h"
#include <stdio.h>
//#include <iostream>
#include <unistd.h> 
//#incilude <stdio.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <sys/time.h>
#define PORT 8080 


// socket to use
//////////////////////////////////////////////
uint8_t sock = SOCKET0;
//////////////////////////////////////////////
int tell_flag;
// define radio settings
//////////////////////////////////////////////
uint8_t power = 15;
//uint8_t power = 5;
//uint32_t frequency = 910000000;
//uint32_t frequency = 915529000;
uint32_t frequency = 916000000;

char spreading_factor[] = "sf7";
char coding_rate[] = "4/5";
uint16_t bandwidth = 250;
//uint16_t bandwidth = 62.5;
char crc_mode[] = "on";
//char crc_mode[] = "off";
//////////////////////////////////////////////
struct timeval stop, start;
// define functions
uint8_t radioModuleSetup(void);

// define data to send

char data[10];
// variable
uint8_t error;


int server_fd, new_socket, valread; 
struct sockaddr_in address; 
int opt = 1; 
int addrlen = sizeof(address); 
char buffer[1024] = {0}; 

char mode;

struct sockaddr_in cli;
unsigned int clilen = sizeof(cli);


void setup() 
{
  printf("Radio P2P example - Sending packets\n\n");

  error = radioModuleSetup();
  
  // Check status
  if (error == 0)
  {
    printf("Module configured OK\n");     
  }
  else 
  {
    printf("Module configured ERROR\n");     
  }  

}


void loop() 
{

    /*
      if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                    (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    }
    */ 
    //valread = unistd::read( new_socket , buffer, 1024);
    
    //memset(buffer, 0, sizeof(buffer));	
    //recvfrom(server_fd,buffer,sizeof(buffer),0,(struct sockaddr*)&cli,&clilen); 
    //printf("%s\n",buffer ); 
    
    //mode = buffer[0];
    //printf("%d\n",sizeof(data));
    int i;
    //for(i=0; buffer[i] != '\0'; i++){
    //	data[i] = buffer[i];
    //}
    data[0] = '0';
    data[1] = '\0';


    printf("data %s\n",data);

    for(int mm=0;mm<1;mm++){
        gettimeofday(&start, NULL);
    	error = LoRaWAN.sendRadio(data);
        gettimeofday(&stop, NULL);
        printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec); 
/*
    if(mode =='1'){
	//printf("here\n");
    	LoRaWAN.setRadioSF(spreading_factor);
	error = LoRaWAN.sendRadio(data);
	//1------
    }
    if(mode == '0'){
	char newdata[] = "000000000000000000000";
	char newsf[] = "sf9";
	LoRaWAN.setRadioSF(newsf);
	error = LoRaWAN.sendRadio(newdata);
	//2------3
    }
    if(mode == '2'){
        char newsf2[] = "sf10";
	LoRaWAN.setRadioSF(newsf2);
	error = LoRaWAN.sendRadio(data);
    }
    */
 	 //LoRaWAN.setRadioSF(spreading_factor);
/*
    if(bandwidth == 125){
	bandwidth = 250;

    }  else{
        bandwidth = 125;
    }

    LoRaWAN.setRadioBW(bandwidth);
*/


  // Check status
/*
  	if (error == 0)
 	{
    		printf("--> Packet sent OK\n");
  	}
  	else 
  	{
    		printf("Error waiting for packets. error = %d\n", error);  
  	}
*/
   }
   delay(1000);
}


/***********************************************************************************
*
* radioModuleSetup()
*
*   This function includes all functions related to the module setup and configuration
*   The user must keep in mind that each time the module powers on, all settings are set
*   to default values. So it is better to develop a specific function including all steps
*   for setup and call it everytime the module powers on.
*
*
***********************************************************************************/
uint8_t radioModuleSetup()
{ 
  uint8_t status = 0;
  uint8_t e = 0;
  char c;  
  //////////////////////////////////////////////
  // 1. switch on
  //////////////////////////////////////////////
//  c = getchar();
  e = LoRaWAN.ON(sock);
  //c = getchar();
  // Check status
  if (e == 0)
  {
    printf("1. Switch ON OK\n");     
  }
  else 
  {
    printf("1. Switch ON error = %d\n",e); 
    status = 1;
  }
  printf("-------------------------------------------------------\n");



  //////////////////////////////////////////////
  // 2. Enable P2P mode
  //////////////////////////////////////////////

  e = LoRaWAN.macPause();

  // Check status
  if (e == 0)
  {
    printf("2. P2P mode enabled OK\n");
  }
  else 
  {
    printf("2. Enable P2P mode error = %d\n", e);
    status = 1;
  }
  printf("-------------------------------------------------------\n");



  //////////////////////////////////////////////
  // 3. Set/Get Radio Power
  //////////////////////////////////////////////

  // Set power
  e = LoRaWAN.setRadioPower(power);

  // Check status
  if (e == 0)
  {
    printf("3.1. Set Radio Power OK\n");
  }
  else 
  {
    printf("3.1. Set Radio Power error = %d\n", e);
    status = 1;
  }

  // Get power
  e = LoRaWAN.getRadioPower();

  // Check status
  if (e == 0) 
  {
    printf("3.2. Get Radio Power OK. "); 
    printf("Power: %d\n",LoRaWAN._radioPower);
  }
  else 
  {
    printf("3.2. Get Radio Power error = %d\n", e); 
    status = 1;
  }
  printf("-------------------------------------------------------\n");



  //////////////////////////////////////////////
  // 4. Set/Get Radio Frequency
  //////////////////////////////////////////////

  // Set frequency
  e = LoRaWAN.setRadioFreq(frequency);

  // Check status
  if (e == 0)
  {
    printf("4.1. Set Radio Frequency OK\n");
  }
  else 
  {
    printf("4.1. Set Radio Frequency error = %d\n", error);
    status = 1;
  }

  // Get frequency
  e = LoRaWAN.getRadioFreq();

  // Check status
  if (e == 0) 
  {
    printf("4.2. Get Radio Frequency OK. "); 
    printf("Frequency: %d\n", LoRaWAN._radioFreq);
  }
  else 
  {
    printf("4.2. Get Radio Frequency error = %d\n", e); 
    status = 1;
  }
  printf("-------------------------------------------------------\n");



  //////////////////////////////////////////////
  // 5. Set/Get Radio Spreading Factor (SF)
  //////////////////////////////////////////////

  // Set SF
  e = LoRaWAN.setRadioSF(spreading_factor);

  // Check status
  if (e == 0)
  {
    printf("5.1. Set Radio SF OK\n");
  }
  else 
  {
    printf("5.1. Set Radio SF error = %e\n", e);
    status = 1;
  }

  // Get SF
  e = LoRaWAN.getRadioSF();

  // Check status
  if (e == 0) 
  {
    printf("5.2. Get Radio SF OK. "); 
    printf("Spreading Factor: %s\n", LoRaWAN._radioSF);
  }
  else 
  {
    printf("5.2. Get Radio SF error = %d\n", e); 
    status = 1;
  }
  printf("-------------------------------------------------------\n");



  //////////////////////////////////////////////
  // 6. Set/Get Radio Coding Rate (CR)
  //////////////////////////////////////////////

  // Set CR
  e = LoRaWAN.setRadioCR(coding_rate);

  // Check status
  if (e == 0)
  {
    printf("6.1. Set Radio CR OK\n");
  }
  else 
  {
    printf("6.1. Set Radio CR error = %d\n", e);
    status = 1;
  }

  // Get CR
  e = LoRaWAN.getRadioCR();

  // Check status
  if (e == 0) 
  {
    printf("6.2. Get Radio CR OK. "); 
    printf("Coding Rate: %s\n",LoRaWAN._radioCR);
  }
  else 
  {
    printf("6.2. Get Radio CR error = %d\n", e); 
    status = 1;
  }
  printf("-------------------------------------------------------\n");



  //////////////////////////////////////////////
  // 7. Set/Get Radio Bandwidth (BW)
  //////////////////////////////////////////////

  // Set BW
  e = LoRaWAN.setRadioBW(bandwidth);

  // Check status
  if (e == 0)
  {
    printf("7.1. Set Radio BW OK\n");
  }
  else 
  {
    printf("7.1. Set Radio BW error = %d\n", e);
  }

  // Get BW
  e = LoRaWAN.getRadioBW();

  // Check status
  if (e == 0) 
  {
    printf("7.2. Get Radio BW OK. "); 
    printf("Bandwidth: %u\n", LoRaWAN._radioBW);
  }
  else 
  {
    printf("7.2. Get Radio BW error = %d\n", e); 
    status = 1;
  }
  printf("-------------------------------------------------------\n");



  //////////////////////////////////////////////
  // 8. Set/Get Radio CRC mode
  //////////////////////////////////////////////

  // Set CRC
  e = LoRaWAN.setRadioCRC(crc_mode);

  // Check status
  if (e == 0)
  {
    printf("8.1. Set Radio CRC mode OK\n");
  }
  else 
  {
    printf("8.1. Set Radio CRC mode error = %d\n", e);
    status = 1;
  }

  // Get CRC
  e = LoRaWAN.getRadioCRC();

  // Check status
  if (e == 0) 
  {
    printf("8.2. Get Radio CRC mode OK. "); 
    printf("CRC status: %u\n",LoRaWAN._crcStatus);
  }
  else 
  {
    printf("8.2. Get Radio CRC mode error = %e\n", e); 
    status = 1;
  }
  printf("-------------------------------------------------------\n");


  //LoRaWAN.setRadioPreamble(0);
  e = LoRaWAN.getRadioPreamble();
  if(e == 0){
  	printf("Preamble number: %u\n", LoRaWAN._preambleLength);
  }



  return status;
}


//////////////////////////////////////////////
// Main loop setup() and loop() declarations
//////////////////////////////////////////////

int main (){
	setup();
	//if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	if ((server_fd = socket(AF_INET, SOCK_DGRAM,  0)) == 0)
    	{ 
        	perror("socket failed"); 
        	exit(EXIT_FAILURE); 
    	}	 
    	/*
    	// Forcefully attaching socket to the port 8080 
    	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                &opt, sizeof(opt))) 
    	{ 
        	perror("setsockopt"); 
        	exit(EXIT_FAILURE); 
    	} 
	*/
    	address.sin_family = AF_INET; 
    	address.sin_addr.s_addr = INADDR_ANY; 
    	address.sin_port = htons( PORT ); 
    
    	// Forcefully attaching socket to the port 8080 
    	if (bind(server_fd, (struct sockaddr *)&address, 
                                sizeof(address))<0) 
    	{ 
        	perror("bind failed"); 
        	exit(EXIT_FAILURE); 
    	} 
	while(1){
		loop();
	}
	return (0);
}

