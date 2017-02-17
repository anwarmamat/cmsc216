#include<stdio.h>
#include<string.h>
void cesar(char *d,char *s)
{
	while(*s){
		int t = *s + 3;
		if (t > 'z') t -= 26;
		*d = t;
		d++;
		s++;
	}
}
void cesar2(char *d,char *s)
{
	while(*s){
		int t = *s - 3;
		if (t < 'a') t += 26;
		*d = t;
		d++;
		s++;
	}
}
int main()
{
	char s[]="lifeistooshorttodosomethingyoudontlike";
	char d[100];
	char d2[100];
	cesar(d,s);
	printf("Original:%s\n", s);
	printf("Encrypted:%s\n", d);
	cesar2(d2, d);
	printf("Decrypted:%s\n", d2);

	return 0;
}
