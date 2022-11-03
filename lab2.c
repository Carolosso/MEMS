#include <stdio.h>
#include <reg515.sfr>
#include <lcd.h>

static int i =0;

static int liczba=0;
static char c1='1';
static char c2='0';
void main(){
	

	init_lcd();

 	T2CON=0x11;
 	CRCH=0xFF;
 	CRCL=0;
 	TH2=0xFF;
 	TL2=0;
 	CCH1=0xFF;
 	
   	CCL1=0x1A;	 //0 - 0% 255- 100% 
	CCEN=8;
 	CLK=1;
 	P3=0xDF;  
	cmd_wr(1);
	char_wr(49);
   	char_wr(48);
   	char_wr('%');

	liczba = 10;
  	while(1){
	   if(kb_test()=='4' && CCL1 > 0x1A ){
	   	CCL1--;
		liczba--;
		c1 = liczba / 10;
		c2 = liczba % 10;
		cmd_wr(1);
		char_wr(c1+48);
		char_wr(c2+48);

		char_wr('%');
	   }
	   if(kb_test()=='6' && CCL1 < 0xF7 ){
	   	CCL1++;
		liczba++;
		cmd_wr(1);
 		c1 = liczba / 10;
		c2 = liczba % 10;
		cmd_wr(1);
		char_wr(c1+48);
		char_wr(c2+48);
 		char_wr('%');
		}
	   for(i =0 ; i<2000; i++){}	
	}

}
