#include <stdio.h>
#include <string.h>

typedef struct{
	int id;
	char name[80];
	float gpa;
}Student;
 	

int main(){

	Student s1={100,"alice", 3.9};
	Student s2;
	Student *p = &s2;
	s2.id = 200;
	strcpy(s2.name, "bob);
	
	p->gpa = 3.95;
	

	return 0;
}