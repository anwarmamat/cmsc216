/*
  print the bit representation of a given value
 */
#include<stdio.h>

void print(char* p,int n){
  int i,j;
  char bits[33]={"--------------------------------"};
  int pos = 31;
  /* print n bytes */
  for(int i = 0; i < n; i++){
    char c = *p;
    /* print 8 bits of a byte */
    for(j = 0; j < 8; j++){
      /* if the last bit is 1 */
      if(c & 0x01 ){
        bits[pos] = '1';
      }else{
	bits[pos] = '0';
      }
      c = c >> 1;
      pos--;
       
    }
    p++;
  }
  printf("%s\n",bits);
}

int main(){
  
  int i = -1;
  print((char*)&i, sizeof(i));

  return 0;

}
