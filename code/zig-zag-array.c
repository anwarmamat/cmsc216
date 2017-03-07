#include <stdio.h>

int main(){

  int *array[3];
  int a[] = {1,2,3,4,5};
  int b[] = {6,7,8,9};
  int c[] = {10,11,12};

  array[0] = a;
  array[1] = b;
  array[2] = c ;
  int size[]={5,4,3,};
 
  int i,j;
  for(i = 0; i <=2; i ++){
    for(j = 0; j < size[i]; j++){
      /*printf("%d\t",array[i][j]);*/
      printf("%d\t", *(*(array+i)+j) );
    }
    printf("\n");
  }
  
  return 0;
}
