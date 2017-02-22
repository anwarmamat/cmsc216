/*
passing 2D arrays as parameter
*/


#include<stdio.h>
#define N 3
#define M 4
/*
void print(int (*)[M]);
*/
void print(int (*)[M]);

int main(){
  int matrix[][M] ={
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  print(matrix);

  return 0;
}

/*
  receive 2D array as an argument 
*/

void print(int m[][M]){
  int i,j;
  for(i = 0; i < N; i++){
    for(j = 0; j < M; j++){
      printf("%d\t", m[i][j]);
      printf("%d\t", *(*(m+i)+j));
    }
    printf("\n");
  }
}


/*                                                                                                
  receive 2D array as a poinrer

*/
/*
void print(int (*m)[M]){
  int i,j;
  for(i = 0; i < N; i++){
    for(j = 0; j < M; j++){
      printf("%d\t", *(*(m+i)+j));
      printf("%d\t", m[i][j]);
    }
    printf("\n");
  }
  }*/
