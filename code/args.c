#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* 

   print the command line arguments

 */

int main(int argc, char *argv[]){
	int i;
	
	if(argc != 4){
		printf("Usage: args param1 param2 param3\n");
		exit(0);
	}
	
	for(i = 0; i < argc; i++){
		printf("%s\n", argv[i]);
	}
	
	return 0;
}
