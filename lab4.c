#include <reg515.sfr>
#include <lcd.h.>
#include <mems.h>
#include <regaduc812.sfr>
unsigned int result;
static int res = 0;
static int a,b,c,d=0;

void main(){

	ADCCON1=0x68;
	init_lcd();
	cmd_wr(1);

	while(1){
		SCONV=1;
		while((ADCCON3 & 128) == 1){}  
		result = ADCDATAH << 8;
		result |= ADCDATAL;
		res = result * 1.222;
	   	
		a = res/1000;
		char_wr(a+48);
		//wypisanie "."
		char_wr(46);
		b = (res - (a*1000))/100;
		char_wr(b+48);
		c = (res - (a*1000) - (b*100))/10;		   
		char_wr(c+48);
		d = res - (a*1000) - (b*100)-(c*10);		
		char_wr(d+48);
		cmd_wr(2);
	}
}
