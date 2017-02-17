/*
  local static variables 
*/

#include<stdio.h>

int foo(){
  static int x = 0;
  x++;
  return x;
}

int bar(){
  static int x;
  x++;
  return x;
}


int main(){
  int i;
  for(i = 0; i < 5; i++){
    printf("called %d times\n",foo());
    printf("called %d times\n",bar());
  }
  return 0;
}
