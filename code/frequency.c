/*
	Calculate the letter frequency

	Usgae: gcc -o frequency.c  frequency
	./freuqnecy < war_peace.txt
*/
#include<stdio.h>

int main()
{
	int freq[256]={0};
	unsigned char n;
    scanf("%c", &n);  /* read a number */
    while (!feof(stdin)) {
    	freq[ n ] += 1;  
    	scanf("%c", &n);  /* read a number */
    }
    printf("Letter\tCount\n");
    int i;
    for(i = 'A'; i <='Z'; i++){
    	printf("%c:\t%d\n", i, freq[i]);
    }
    for(i = 'a'; i <='z'; i++){
    	printf("%c:\t%d\n", i, freq[i]);
    }
    
    int largest = 0;
    for(i = 'A'; i <= 'z'; i++){
      if(freq[i] > freq[largest]) largest = i;
    } 
    printf("==============================\n");  
    printf("%c:\t%d\n",largest,freq[largest]);
    
  return 0;
}
