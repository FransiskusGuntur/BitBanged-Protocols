#ifndef MAX7219_H
#define MAX7219_H

#include "8051.h"

#define CLK  P2_0           
#define DIN  P2_1                
#define DOUT P2_2          
#define LOAD_MAX P2_4       //MAX7219

//define 7-segment reigister
#define DECODE_MODE  0x09
#define INTENSITY    0x0A
#define SCAN_LIMIT   0x0B
#define SHUT_DOWN    0x0C
#define DISPLAY_TEST 0x0F
#define matrixnum 1

void sendbyte(unsigned char address, unsigned char data);
void write7219(unsigned char address, unsigned char data);
void write_multi_unit(unsigned char unit, unsigned char address, unsigned char data);
void Init(void);


#endif
