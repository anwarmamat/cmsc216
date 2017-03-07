#include<stdio.h>
int main(){
  int a[3][4]={{10,20,30,40},{5,6,7,8},{90,100,110,120}};

  int (*p)[4] = a;

  printf("%d\n",**p); // 10   (0,0)
  printf("%d\n",**p + 1); //11   (0,0) + 1
  printf("%d\n",*( (*p) + 1)); //20 (0,1)
  printf("%d\n",** (p+1) ); //5  (1,0)

  printf("%d\n",*(  *(p+2)+ 3 )); //120  (2,3)
  
  
  return 0;

}
