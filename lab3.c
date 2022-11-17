#include <stdio.h>
#include <reg515.sfr>

static int P1_values[6] = {222,219,249,237,231,246};

static int P4_values[6] = {3,1,5,4,6,2};
static int mask = 7;//111
static int col = 0;
_interrupt 5 void przerwanie(void){

  while(P4&mask !=P4_values[col]){}
  //col = (col > 5) ? 0 : col++;
  col++;
  if(col>5)col=0;
   
  P1=P1_values[col];
  
  TF2=0;
}


void main(){
	EAL = 1;
	ET2 = 1;
	T2R1 = 1;
	T2I0 = 1;
}
