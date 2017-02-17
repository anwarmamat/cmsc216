/*

sort strings with qsort library function

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(char **s, int n){
  int i = 0;
  for(i = 0; i < n; i++){
    printf("%s\n", s[i]);
  }
	   
    
}


/* qsort C-string comparison function */ 
int cstring_cmp(const void *a, const void *b) 
{ 
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);

} 

int main(){
  
  char *str[] ={"ascendio", "avada kedavra","crucio","stupefy",
		"expecto patronum","expulso","obliviate","accio",
		"lumos", "expelliarmus"};
  
  
  size_t strings_len = sizeof(str) / sizeof(char *);
    
  /* sort array using qsort functions */ 
  qsort(str, strings_len, sizeof(char *), cstring_cmp);

  print(str,10);
  return 0;

}
