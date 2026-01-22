#include "seven_segment.h"


void sendbyte(unsigned char address, unsigned char data) {
   unsigned char i;
   for (i = 0; i < 8; i++) {
      CLK = 0;
      DIN = (address & 0x80) ? 1 : 0;

      address <<= 1;
      CLK = 1;
   }
   for (i = 0; i < 8; i++) {
      CLK = 0;
      DIN = (data & 0x80) ? 1 : 0;

      data <<= 1;
      CLK = 1;
   }
}

void write7219(unsigned char address, unsigned char data) {
   unsigned char count;
   LOAD_MAX = 0;
  	for (count = 1; count <= matrixnum; count++) {
      sendbyte(address, data);
   }
   LOAD_MAX = 1;
}


void write_multi_unit(unsigned char unit, unsigned char address, unsigned char data) 
{
    unsigned char count;
    LOAD_MAX = 0;
    for (count = matrixnum; count > unit; count--) {       
        sendbyte (0x00, 0x00);                     // write 0 (no-op) to prev unused unit(s)
    } 

   	sendbyte (address, data);  

   	for (count = unit-1; count > 0; count--) {  //write 0 (no-op) to remaining unused unit(s)
   		sendbyte (0x00, 0x00);                      
    }
   LOAD_MAX = 1;
}


void Init(void) {   
   unsigned char i;

   write7219(SHUT_DOWN, 0x01);
   write7219(DISPLAY_TEST, 0x00);
   write7219(DECODE_MODE, 0x00);
   write7219(SCAN_LIMIT, 0x07);
   write7219(INTENSITY, 0x00);

   for (i = 1; i <= 8; i++) {
    	write7219(i, 0x00);
   }
}