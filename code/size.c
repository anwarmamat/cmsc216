#include<stdio.h>

int main(){
  float a[]={4,5,6,7};

  float *p = a;
  long p1 = (long ) p;
  p++;
  long p2 = (long ) p;

  int d = p2 - p1;

  printf("size of int = %d\n", d);

  printf("%p\n",p2);

  float f =  *((float*)p2);
  printf("\n%f\n", f);
  
  return 0;
}
