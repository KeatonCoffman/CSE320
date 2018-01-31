#include "/user/cse320/Projects/project06.support.h"
#include <stdio.h>

int main(){
  float a=5.625;
  
  float b=17.75;
  
  float c= add(a,b);
  
  printf("5.625+17.75: %f  \n", c);
  

  a=2.45;
  
  b=5.75;
  
  c= add(a,b);
  
  printf("2.45+5.75: %f  \n", c);
  

  a=1.01;
  
  b=1.01;
  
  c= add(a,b);
  
  printf("1.01+1.01: %f  \n", c);
  

  a=-1.01;
  
  b=2.01;
  
  c= add(a,b);
  
  printf("-1.01+2.01: %f  \n", c);
  

  a=-5.625;
  
  b=17.75;
  
  c= add(a,b);
  
  printf("-5.625+17.75: %f  \n", c);
  

}
