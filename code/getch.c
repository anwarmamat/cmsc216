#include <stdio.h>
//#include <conio.h>
int main()
{
	char c = 0;
	while( !(c == 10 || c == 13))
	{
		c = getchar();
		if(c == 27)
			continue;
		printf("%c\n",c);
	}
}