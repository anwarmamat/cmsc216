
#include<stdio.h>
int x = 10;   /* global variables */

void foo(){
  printf("in foo\n");
  int a = 200;
  x++;      /* modifies the global */
  printf("a=%d\tx=%d\n",a,x);
}

int main(){
  printf("in main\n");
  int a = 100;
  foo();
  printf("a=%d\tx=%d\n",a,x); /* a=100, x= 101 */

  return 0;
}
