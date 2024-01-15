#include<reg52.h>
#define ALL_OFF 0x00
sbit LED1=P2^1;
sbit LED2=P2^2;
sbit LED3=P2^3;
sbit LED4=P2^4;
sbit LED5=P2^5;
sbit LED6=P2^6;
sbit LED7=P2^7;
sbit SW=P1^4;
sbit LED=P1^1;
#define OFF 0
#define ON 1
unsigned char Dice=0;
void MsDelay(unsigned int time)
{
unsigned int i,j;
for(i=0;i<time;i++)
{
for(j=0;j<1000;j++);
}
}
void main(void)
{
P2=0x00;
P1=0xF0;
LED=ON;
MsDelay(500);
LED=OFF;
MsDelay(500);
LED=ON;
MsDelay(500);
LED=OFF;
for(;;)
{
if(SW==0)
{
// MsDelay(500);
switch(Dice)
{
case 1:
LED7=ON;
break;
case 2: LED3=ON;
LED4=ON;
break;
case 3: LED3=ON;
LED4=ON;
LED7=ON;
break;
case 4: LED1=ON;
LED5=ON;
LED6=ON;
LED2=ON;
break;
case 5: LED1=ON;
LED5=ON;
LED2=ON;
LED6=ON;
LED7=ON;
break;
case 6: LED1=ON;
LED2=ON;
LED3=ON;
LED4=ON;
LED5=ON;
LED6=ON;
break;
}
MsDelay(500);
P2=ALL_OFF;
}
else
{
Dice++;
if(Dice==7)Dice=1;
}
}
}