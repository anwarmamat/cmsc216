#include<stdio.h>
#include<string.h>
void string_copy(char *dst, char *src);
void concat(char *dst, char *src);

int main()
{
	char s[]="Happy life";
	char d[100]="Happier Life";
	concat(d,s);
	printf("%s\n%s\n", s,d);
	return 0;
}

void concat(char *dst,char *src){
	int l = strlen(dst);
	char *p = dst+l;
	while(*src){
		*p++=*src++;
	}
	*p='\0';
}

void string_copy(char dst[], char src[])
{
	int i;
	for(i = 0; i < strlen(src);i++)
		dst[i] = src[i];
	dst[i] = '\0';
	
	/*while(src){
		*dst++=*src++;
	}
	*dst='\0';*/
}
