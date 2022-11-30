#include <LCD.h>
#include <regaduc812.sfr>
void main()
{
unsigned int result;
int a,b,c,d,i;
l_start();
ADCCON1=0x68;
SCONV=1;
while(1){
  SCONV=1;
  while(ADCCON3 & 0x80){
    result = ADCDATAH << 8;
    result |= ADCDATAL;
    result=result*1.221;
    a=result/1000;
    b=(result-a*1000)/100;
    c=(result-a*1000-b*100)/10;
    d=result-a*1000-b*100-c*10;
    l_cmd(1);
    l_out(a+48);
    l_out(44);
    l_out(b+48);
    l_out(c+48);
    l_out(d+48);
    for(i=5000000;i>0;i--);
    }
 }
}
