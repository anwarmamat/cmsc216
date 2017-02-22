#include <stdio.h>
#include <string.h>

int main () {

   unsigned char *str1[] = {
     "abcdef",
      "1234567890"
   };
   
   unsigned char str2[][11] = {
     "abcdef",
      "1234567890"
   };

   /*str2[0][1]='B';*/
   
   
   int i = 0;

   for ( i = 0; i < 2; i++) {
      printf("str1[%d] = %s\n", i, str1[i] );
   }

   printf("%d\n", sizeof(str1[0]));
   printf("%d\n", sizeof(str2[0]));

   printf("%d\n", strlen(str1[0]));
   printf("%d\n", strlen(str2[0]));


   printf("&str1[0][0]=%ld\n", &(str1[0][0]));
   printf("str1[0]=%ld\n", (str1[0]));
   printf("str1[1]=%ld\n", (str1[1]));
   printf("str2[0]=%ld\n", (str2[0]));
   printf("str2[1]=%ld\n", (str2[1]));

   
   
   char *p = (char *) (str1[0]);
   printf("p=%ld\n", p);
   
   
   for(int i = 0; i < 18; i++){
     printf("%d,",*p++);
   }
   printf("\nprinting str2:\n");
   p = (char *) (str2[0]);
   printf("p=%ld\n", p);

   printf("printing str2:\n");
   for(int i = 0; i < 22; i++){
     printf("%d,",*p++);
   }
   
   return 0;
}
