#include <stdio.h>
#include <reg515.sfr>
#include <lcd.h>

static int komutacja1_4[4] = {8,2,4,1};
static int i = 0;	
static int j = 0;
void main(){
	EAL = 1;
	ET2 = 1;
	T2R1 = 1;
	T2I0 = 1;
	while(1){
		if(kb_test() == '4'){
			//if(CRC >= 20) CRCH--;
			CRCH--;
		}
		if(kb_test() == '6'){
		   //if(CRC <=2.5) CRCH++;
			CRCH++;
		}
		for(j = 0; j < 2000; j++){}
	}
}
_interrupt 5 void przerwanie(void){
	if(i == 4) i = 0;
	P1 = komutacja1_4[i];
	i++;
	TF2 = 0;
}
