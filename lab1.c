#include <LCD.h>
#include <reg515.sfr>

int k[]={8,2,4,1};
int i=0;

void main()
{
	EAL=1;
	ET2=1;
	T2R1=1;
	T2I0=1;
}
_interrupt 5 void n_f(void)
{
	P1=k[i];
	i++;
	if (i>3)
	{
		i=0;
	}
	TF2=0;
}
