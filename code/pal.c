/*
  check if a string is a palindrome 
*/
#include<stdio.h>
#include<string.h>

int pal(char *s){
	char *t = s + strlen(s)-1;
	while( s < t){
		if(*s != *t) 
			return 0;
		else{
			s++;
			t--;
		}
	}
	return 1;
}


int main()
{
	char src[]="racecar";
	int r = pal(src);
	if(r)
		printf("%s is a palindrome\n", src);
	else
		printf("%s is NOT a palindrome\n", src);
	return 0;
}
