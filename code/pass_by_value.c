#include<stdio.h>

void foo(int x){
  x  = 200;
  printf("x=%d\n",x);
}

int main(){
  int a = 100;
  foo(a);
  //return from foo
  printf("a=%d\n",a);
  
  scanf("%d", &a);
  printf("a=%d\n",a);
  return 0;
}
