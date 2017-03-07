#include<stdio.h>
#include<string.h>
int main(){
  typedef struct {
    char name[81];
    int id;
    float gpa;
  } Student;

  Student s1;
  Student s2={"alice", 100, 3.9};
  printf("size of s1=%d\n", sizeof(s1));
  printf("size of s1=%d\n", sizeof(s2));

  strcpy(s1.name,"bob");
  s1.id = 200;
  s1.gpa = 3.95;

  Student s3 = s2;

  Student *p = &s3;;
  
  
  printf("%s\t%d\t%f\n", s2.name, s2.id,s2.gpa);
  printf("%s\t%d\t%f\n", s1.name, s1.id,s1.gpa);
  printf("%s\t%d\t%f\n", p->name, p->id,s3.gpa);


  return 0;
}





  
