#include<stdio.h>

int main(){

  enum week {sunday,monday, tuesday=10, wednesday, thursday, friday, saturday };

  enum week today;
  today = wednesday;
  printf("Day %d\n",today);

  enum week day = tuesday;
  while(day <= saturday){
    printf("%d\t", day++);
  }
  printf("\n");
  return 0;
  
}
