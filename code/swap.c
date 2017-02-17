/*
  swap the values of two wariables
 */
#include<stdio.h>
void swap(int*,int*);
int main(){
  int x = 10;
  int y = 20;
  printf("x=%d\ty=%d\n",x,y);
  swap(&x,&y);  /* swap the values of x and y */
  printf("x=%d\ty=%d\n",x,y);
  return 0;
}

void swap(int *a, int *b){
  printf("a=%d\tb=%d\n",a,b);
  int  t = *a;
  *a = *b;
  *b = t;
  printf("a=%d\tb=%d\n",a,b);
}
