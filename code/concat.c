#include<stdio.h>
#include<string.h>

void concat(char *dst, char *src){

	int len = strlen(dst);
	int len_src = strlen(src);
	char news[len+len_src];


	int i;
	for(i = 0; i <= len_src; i++){
		dst[len+i] = src[i];
	}
}
int main(){

	char s1[20]="hello";;
	char s2[]="world";;
	concat(s1,s2);
	
	printf("%s\n",s1);
	return 0;
	
}