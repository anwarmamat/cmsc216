/*
  global and local scope
 */
#include<stdio.h>

int x = 100;
int foo();
int bar();
int main(){
  int i = 100;
  x = 50;
  foo();
  printf("x=%d\n", x);
  bar();
  printf("x=%d\n", x);
}

int foo(){
  printf("in foo\n");
  int i = 200;
  printf("i=%d\n",i);
  {
    int i = 201;
    i += 1;
    printf("i=%d\n",i);
  }
  printf("i=%d\n",i);
  x += 10;
}

int bar(){
  printf("in bar\n");
  int i = 300;
  printf("i=%d\n",i);
  x *= 2;
}
