/*
  main.c   countWords
  Anwar Mamat  11/29/15.
*/

#include<stdio.h>
#include<stdlib.h>
#include <dirent.h>
#include<string.h>
#include <pthread.h>
#include<time.h>
#define MAX_FILE_COUNT 100000
int countFiles(const char *path);	//counts the input files from given path
void get_files(char **file_name, const char *path);	//read all input file names
char * get_file_name(char **file_names);	//get a non-processed file
void * process_files(void *);	//count the words in a file
//#define NUM_THREADS 1		//number of threads
int word_count = 0;		//total word count
int file_count = 0;		// number of input files
char *path = "outputs3";		//input file path

int NUM_THREADS = 1;		//number of threads

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[]){ 
	if(argc == 2){
		int n = atoi(argv[1]);
		NUM_THREADS = n;
	}
    file_count = countFiles(path);
    char **file_names = NULL;
    pthread_t threads[NUM_THREADS];
    //clock_t start, stop;
    struct timespec start, finish;
    
    //unsigned long elapsed = 0;
    float elapsed = 0;
    if(file_count > 0 && file_count < MAX_FILE_COUNT){
        printf("Number of files = %d\n", file_count);
        file_names = malloc(file_count * sizeof(char *));
        get_files(file_names,path);
        
        //start = clock();	//start timer
        clock_gettime(CLOCK_MONOTONIC, &start);
        
        for(int i = 0; i < NUM_THREADS; i++){
        	 pthread_create(&threads[i], NULL, process_files, file_names);
        }
        for(int i = 0; i < NUM_THREADS; i++){
        	 pthread_join(threads[i], NULL);
        }
        //stop = clock();
        clock_gettime(CLOCK_MONOTONIC, &finish);
        elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        //elapsed = stop - start;	//calculate elapsed time
    }
    
    for(int i = 0; i < file_count; i++){
        free(file_names[i]);
    }
    free(file_names);
    printf("Numer of words=%d\n", word_count);
    //printf("Elapsed time = %lu\n", elapsed/CLOCKS_PER_SEC);
    printf("Elapsed time = %f\n", elapsed);
}
/*
		count words in a file
*/
void * process_files(void *t){
	char ** files = (char **) t;
	while(1){
    	char *file = get_file_name(files);
    	if(file == NULL) break;
    	char buf[1024]="";
    	char filename[256];
    	int count = 0;
    	strcpy(filename, path);
    	strcat(filename,"/");
    	strcat(filename, file);
    	if(file != NULL){
        	//printf("%s\n", filename);
        	FILE *fp = fopen(filename,"r");
        	if(fp == NULL) return 0;
        	while(!feof(fp)){
            	fgets(buf,1023, fp);
            	//printf("%s\n", buf);
            	char *ch = buf;
            	while(*ch){
                	if(*ch=='\n') {ch++; continue;}
                	while(*ch == ' ' && ch < buf + 1023) ch++;
                	if(*ch >='a' && *ch <='z') {count++;
                	//printf("\nnew word:"); printf("%c",*ch);
                	ch++;}
                
                	while(*ch != ' ' && ch < buf + 1023) {
                	//printf("%c",*ch);
                	ch++;}
            	}
            	memset(buf,0,1024);
            	//printf("----------- one line done\n");
        	}
        	fclose(fp);
    	}
    	//printf("%d\t%d\n", (int)pthread_self(), count);
    	pthread_mutex_lock( &mutex1 );
			word_count += count;
  	    pthread_mutex_unlock( &mutex1 );
	   

    }
    return 0;
}
/*
	get a non-processed file
*/
char * get_file_name(char **file_names){
    static int i = 0;
    if(i < file_count){
        return file_names[i++];
    }else
        return NULL;
}
/*
	read the list of input files
*/
void get_files(char **file_name_list, const char *path)
{
    int file_count = 0;
    DIR * dirp;
    struct dirent * entry;
    char **cur = file_name_list;
    if((dirp = opendir(path)) != NULL){
        int i = 0;
        while ((entry = readdir(dirp)) != NULL) {
            if (entry->d_type == DT_REG) { /* If the entry is a regular file */
                char *t = (char*) malloc(strlen(entry->d_name+1));
                strncpy(t,entry->d_name, strlen(entry->d_name));
                cur[i++] = t;
            }
        }
        closedir(dirp);
    }else{
        perror ("Could not open folder");
    }
    
}

/*
	Get the number of files in a given folder
 */
int countFiles(const char *path){
    int file_count = 0;
    DIR * dirp;
    struct dirent * entry;
    if((dirp = opendir(path)) != NULL){
        while ((entry = readdir(dirp)) != NULL) {
            if (entry->d_type == DT_REG) { /* If the entry is a regular file */
                file_count++;
            }
        }
        closedir(dirp);
    }else{
        perror ("Could not open folder");
        return EXIT_FAILURE;
    }
    
    return file_count;
}
