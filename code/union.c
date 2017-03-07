#include<stdio.h>
#include<string.h>

int main(){

  typedef union {
    int x;
    char s[4];
  } Test;

  Test s1;
  strcpy(s1.s, "ABC");  /*0x41 0x42 0x43 */ 

  printf("size=%d\n", sizeof(s1));

  printf("0x%x\tdecimal:%d\n", s1.x,s1.x);
  s1.x++;
  printf("0x%x\tdecimal:%d\n", s1.x,s1.x);

  printf("%s\n", s1.s);
  return 0;

}
