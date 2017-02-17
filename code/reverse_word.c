/********************************************************
*                                    				*
*     Reverse each word is a string               	*
*                                   				*
*                                   				*
*********************************************************/
#include <stdio.h>
#include<string.h>
void reverseWord(char *, int , int);
void reverse(char *);
int main()
{
    char src[] = {"My name is Abc Xyz. My dog's name is Max."};
    printf("%s\n",  src);
    reverse(src);
    printf("%s\n",  src);
}

void reverse(char *src)
{
	int len = strlen(src);
     int s = 0;     //start index of a word
     int t = 0;     //end index of a word
     while(t < len){
          while((isalpha(src[t]) || src[t] == '\'') && t < len) t++;     //find the end index of a word
          reverseWord(src,s,t-1);          //reverse the word at [s, t-1]
          while(!isalpha(src[t])  && t < len) t++;     //find the start index of next word
          s = t;          // set the start index of the next word
     }
}

/****************************************
*                             		*
*     reverse a word                *
*                         			*
*****************************************/
void reverseWord(char *str, int s, int t)
{
     char temp;
     while (s < t){
          temp = str[s];
          str[s] = str[t];
          str[t] = temp;
          t--;
          s++;
     }
         
}
