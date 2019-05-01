#include<stdio.h>
#include<stdlib.h>		// for malloc and realloc

#define MAX 50

struct student{
	int roll;
	char name[MAX];
	char branch[MAX];
	int semester;
	int no_of_course;
	char **course;
	struct student * next_student;
};


struct instructor{
	int id;
	char name[MAX];
	int no_of_course;
	char **course;
	struct instructor * next_instructor;

};

struct course{
	int code;
    char name[MAX];
    int credits;
    int no_of_instructors;
    int **instructor_ids;
    int no_of_students;
    int **student_roll;

};

struct student * first_student;
struct instructor * first_instructor;
struct course * first_course;

void load_student_data(){	// loading all the student data to list from txt file
	FILE * fp1 , * fp2;
	fp1 = fopen("student_file.txt", "a+");
	fp2 = fopen("student_file.txt", "a+");
	int i;
	while(fscanf(fp1,"%d",&i)!=-1){		// While an integer(roll number) is successfully read
		fseek(fp1,ftell(fp2),SEEK_SET);	// seek back to read the roll again
		create_student_profile(-1);
		struct student * s = first_student;
		while(s->next_student!= NULL)
			s = s->next_student;
	fscanf(fp1,"%d",&(s->roll));
	fscanf(fp1," %s",(s->name));
	fscanf(fp1," %s",(s->branch));
	fscanf(fp1," %d",&(s->semester));
	fscanf(fp1," %d",&(s->no_of_course));
		s->course = (char **)calloc(s->no_of_course,sizeof(char *));
		for(int i=0;i<(s->no_of_course);i++){
			s->course[i] = (char *)calloc(MAX,sizeof(char ));
			fscanf(fp1,"%s",s->course[i]);
		}
		fseek(fp2,ftell(fp1),SEEK_SET);	// move reference pointer to the end of the current student details
	}
}
