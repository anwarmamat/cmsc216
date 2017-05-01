/*
  this program generates stackoverflow error.
 */
#include<stdio.h>

int main(){
  static int count  = 0;
  count++;
  printf("%d\n",count);
  int a[1000];
  double b[1000];
  main(); /* call main recursively */

  return 0;
  
}
