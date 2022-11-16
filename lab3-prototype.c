#include <stdio.h>

static int P1_values[8] = [0b01111011,0b11011011,0bXXXXXX11,0bXXXXXX11,0bXXXXXX11,0bXXXXXX11,0bXXXXXX11,0bXXXXXX11]; // poszczegolne kolumny
P1=P1_values[0]; //bitowo

int is_P4(int col){
  switch(col){
    case 0:
      if(P4_0==1 && P4_1==1 && P4_2==0){
        return 1;
      }
      else {
        return 0;
      }
    case 1:
      if(P4_0==1 && P4_1==0 && P4_2==0){
        return 1;
      }
      else return 0;
    case 2:
      if(P4_0==1 && P4_1==0 && P4_2==1){
        return 1;
      }
      else return 0;
    case 3:
      if(P4_0==0 && P4_1==0 && P4_2==1){
        return 1;
      }
      else return 0;
    case 4:
      if(P4_0==0 && P4_1==1 && P4_2==1){
        return 1;
      }
      else return 0;
    case 5:
      if(P4_0==0 && P4_1==1 && P4_2==0){
        return 1;
      }
      else return 0;
  }
}

int col_of_P1(){
  if(P1_0==0 && P1_1==1 && P1_2==1 && P1_3==1 && P1_4==1 && P1_5==0 && P1_6==1 && P1_7==1){
    return 0;
  }
  else if(P1_0==1 && P1_1==1 && P1_2==0 && P1_3==1 && P1_4==1 && P1_5==0 && P1_6==1 && P1_7==1){
    return 1;
  }
  else if(P1_0==X && P1_1==X && P1_2==X && P1_3==X && P1_4==X && P1_5==X && P1_6==1 && P1_7==1){
    return 2;
  }
  else if(P1_0==X && P1_1==X && P1_2==X && P1_3==X && P1_4==X && P1_5==X && P1_6==1 && P1_7==1){
    return 3;
  }
  else if(P1_0==X && P1_1==X && P1_2==X && P1_3==X && P1_4==X && P1_5==X && P1_6==1 && P1_7==1){
    return 4;
  }
  else if(P1_0==X && P1_1==X && P1_2==X && P1_3==X && P1_4==X && P1_5==X && P1_6==1 && P1_7==1){
    return 5;
  }
}

void assign_P1(){
  P1 = (col_of_P1+1<6) ? P1_values[col_of_P1+1] : P1_values[0]; // przypisz do P1 wartosc kolejnej kolumny jezeli spelniony jest warunek że licznik kolumny istnieje, w przeciwnym wypadku przypisz pierwsza kolumne;
}

void interrupt 5 (void){
  if(is_P4(col_of_P1)){
    assign_P1();
  }
}

void main(){

}
