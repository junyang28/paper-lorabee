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
 *  Implementation:    Luismi Marti, Ruben Martin  
 */

#include "arduPiLoRaWAN.h"

// socket to use
//////////////////////////////////////////////
uint8_t sock = SOCKET0;
//////////////////////////////////////////////

// define radio settings
//////////////////////////////////////////////
uint8_t power = 15;
//uint32_t frequency = 915600000;
uint32_t frequency = 915529000;
//uint32_t frequency = 916000000;
char spreading_factor[] = "sf11";
char coding_rate[] = "4/5";
uint16_t bandwidth = 500;
//uint16_t bandwidth = 62.5;
//char crc_mode[] = "on";
char crc_mode[] = "off";
//////////////////////////////////////////////

// define functions
uint8_t radioModuleSetup(void);

// define data to send
//char data[] = "0102030405060708090A0B0C0D0E0F";
//char data[] = "111111111111111";
//char data[] = "000000000000000";
char data[] = "0000";
// variable
uint8_t error;


void setup() 
{
  printf("Radio P2P example - Sending packets\n\n");

  // module setup
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
char data0[] = "0000";
char data1[] = "1000";
char data2[] = "0100";
char data3[] = "0010";
char data00[] = "0001";
char data01[] = "F000";
char data02[] = "0F00";
char data03[] = "00F0";
char data000[] = "000F";
char data001[] = "4000";
char data002[] = "0400";
char data003[] = "0040";
char data0000[] = "0004";
char data0001[] = "0D";
char data0002[] = "0E";
char data0003[] = "0F";
char data00000[] = "00000";
char data00001[] = "00001";
char data00002[] = "00002";
char data00003[] = "00003";
char data000000[] = "000000";
char data000001[] = "000001";
char data000002[] = "000002";
char data000003[] = "000003";
void loop() 
{
  // Send packet
 
  error = LoRaWAN.sendRadio(data0);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }


  error = LoRaWAN.sendRadio(data1);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }


  error = LoRaWAN.sendRadio(data2);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

  
  error = LoRaWAN.sendRadio(data3);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }



  error = LoRaWAN.sendRadio(data00);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }


  error = LoRaWAN.sendRadio(data01);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }


  error = LoRaWAN.sendRadio(data02);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }


  error = LoRaWAN.sendRadio(data03);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

  
  error = LoRaWAN.sendRadio(data000);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }


  error = LoRaWAN.sendRadio(data001);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

 
  error = LoRaWAN.sendRadio(data002);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

  
  error = LoRaWAN.sendRadio(data003);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

  
  error = LoRaWAN.sendRadio(data0000);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

  /*
  error = LoRaWAN.sendRadio(data0001);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

 
  error = LoRaWAN.sendRadio(data0002);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

  
  error = LoRaWAN.sendRadio(data0003);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

  error = LoRaWAN.sendRadio(data00000);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

  
  error = LoRaWAN.sendRadio(data00001);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

 
  error = LoRaWAN.sendRadio(data00002);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

  
  error = LoRaWAN.sendRadio(data00003);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

  error = LoRaWAN.sendRadio(data000000);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

  
  error = LoRaWAN.sendRadio(data000001);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

 
  error = LoRaWAN.sendRadio(data000002);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }

  
  error = LoRaWAN.sendRadio(data000003);
  if (error == 0)
  {
    printf("--> Packet sent OK\n");
  }
  else 
  {
    printf("Error waiting for packets. error = %d\n", error);  
  }
*/
/*
  if(bandwidth == 125){
	bandwidth = 250;

}  else{
        bandwidth = 125;
}
  LoRaWAN.setRadioBW(bandwidth);
*/


  // Check status

 
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
  
  //////////////////////////////////////////////
  // 1. switch on
  //////////////////////////////////////////////

  e = LoRaWAN.ON(sock);

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


  return status;
}


//////////////////////////////////////////////
// Main loop setup() and loop() declarations
//////////////////////////////////////////////

int main (){
	setup();
	while(1){
		loop();
	}
	return (0);
}

