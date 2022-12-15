#include <lcd.h>
#include <mems.h>
#include <regaduc812.sfr>

#define ac1 8306
#define ac2 -1001
#define ac3 -14008
#define ac4 33716
#define ac5 25912
#define ac6 24338
#define b1 6515
#define b2 32
#define mb -32768
#define mc -11786
#define md 2264

static long a,b,c,d,e;
static int oss=3;
static long x1,x2,x3,b3,b6,p;
static unsigned long b4,b7;

void main(){

	bus_init();
	init_lcd();

	while(1){
		unsigned int UT = BMP180_read_UT();
		unsigned long UP = BMP180_read_UP(oss);

		x1=((long)(UT-ac6)*(long)ac5)/32768;
		x2=((long)mc*2048)/(x1+(long)md);
		b6=(x1+x2)-4000;
		x1=((long)b2*((b6*b6)/4096))/2048;
		x2=((long)ac2*b6)/2048;
		x3=x1+x2;
		b3=((((long)ac1*4+x3)<<oss)+2)/4;
		x1=((long)ac3*b6)/8192;
		x2=((long)b1*((b6*b6)/4096))/65536;
		x3=((x1+x2)+2)/4;
		b4=ac4*(unsigned long)(x3+32768)/32768;
		b7=((unsigned long)UP-b3)*(50000>>oss);
		if(b7<80000000)p=(b7*2)/b4;
		else p=(b7/b4)*2;
		x1=(p/256)*(p/256);
		x1=(x1*3038)/65536;
		x2=((-7357*p)/65536);
		p= p +((x1+x2+3791)/16);
		

		a = p/10000;		 //91234 /10000 = 9
		char_wr(a+48);
		b = (p - (a*10000))/1000; //1234/1000 = 1
		char_wr(b+48);
		c = (p - (a*10000) - (b*1000))/100;	//234/100 =2 
		char_wr(c+48);
		char_wr(46);   //przecinek
		d = (p - (a*10000) - (b*1000)-(c*100))/10; //34/10 = 3
		char_wr(d+48);
		e = p - (a*10000) - (b*1000)-(c*100)-(d*10);  //3
		char_wr(e+48);

		char_wr(104);	 //h
		char_wr(80);	//P
		char_wr(97);	//a
		cmd_wr(2);
	}
}

