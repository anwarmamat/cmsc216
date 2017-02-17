/*
      Convert a number to a US English word representation.
      Anwar Mamat
*/

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
char* convert(int);
char* aux(int,int, char*);
    char *small[] = {"", "one", "two", "three", "four",
                              "five", "six", "seven", "eight", "nine",
			      "ten", "eleven", "twelve", "thirteen", "fourteen",
                              "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
 

    char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty",
                             "sixty", "seventy", "eighty", "ninety"};
 

/* splits the numer to left and right two parts and 
   convert them recursivelt
*/
char *aux(int num, int v, char * str){
    int l = num / v;
    int r = num % v;
    char *t = (char *)malloc(1024);
    char* s = convert(l);
    strcpy(t, s);
    if(l > 20) free(s); /* no malloc if num < 20 */
    strcat(t, str);
    s = convert(r);
    strcat(t,s);
    if(r > 20) free(s); /* no malloc if num < 20 */
    return t;
}

/*
 Convert a number to a US English word representation. 
*/

char* convert(int num){
  if(num < 20) return small[num];
  else if (num < 100) {
    int l = num / 10;
    int r = num % 10;
    char *t = (char *)malloc(1024);
    strcpy(t,tens[l]);
    strcat(t, " ");
    strcat(t,convert(r));
    return t;
  }else if(num < 1000) {
    return aux(num, 100, " hundred ");
  }else if(num < 1000000) {
    return aux(num, 1000, " thousand ");
  }else if(num < 1000000000) {
    return aux(num, 1000000, " million ");
  }
  else
    return "error";
}


int main(){
  int n = 12354321;
  char *word = convert(n);
  printf("%d \t %s\n",n, word);
  return 0;
}
