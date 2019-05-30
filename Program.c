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

void modify_student(int roll, char c){
	struct student *s2, *s1, *s = first_student;
	while(s->next_student!=NULL && s->roll!=roll)
		s = s->next_student;
	if(s->roll != roll){
		printf("The roll doesn't exists \n");
		return ;
	}
	if(c == 'm')	// if strudent details is to be updated 
		update_student_profile(s, roll);

	else {		// if student profile is to be deleted 
		if(first_student->roll == roll){	// if the profile to be deleted is starting item
			s = first_student;
			first_student = first_student->next_student;
		}
		else {		// profile to be deleted lies somewhere in between 
			s1 = first_student;
			while(s1 -> next_student != s)	// find parent node to the node of profile to be deleted
				s1 = s1->next_student;
			s1->next_student = s->next_student;
		}
		free(s);
	}

}

void create_student_profile(int roll){
struct student *s2, * s1 = (struct student *)calloc(1, sizeof(struct student));
	if(first_student==NULL){
		first_student=s1;
		return ;
	}
	s2 = first_student;
	while(s2->next_student!=NULL){
		if(s2->roll == roll){
			printf("The student already exists\n");
			return ;
		}
		s2= s2->next_student;
	}
	s2->next_student=s1;
}

void update_student_profile(struct student * s, int roll){
	s->roll = roll;

	printf("enter student first name : \n");
	scanf(" %s",(s->name));

	printf("enter student branch : \n");
	scanf(" %s",(s->branch));

	printf("enter student semester : \n");
	scanf(" %d",&(s->semester));

	printf("enter no of courses : \n");
	scanf(" %d",&(s->no_of_course));

	s->course = (char **)calloc(s->no_of_course,sizeof(char *));
	for(int i=0;i<(s->no_of_course);i++){
		printf("Enter course %d : \n",i+1);
		s->course[i] = (char *)calloc(MAX,sizeof(char ));
		scanf("%s",s->course[i]);
	}
	printf("\n");
}

 void update_student_file(){	// saving all the changes to the txt file 
	FILE * fp = fopen("student_file.txt","w+");
	struct student * s = first_student;
	while(s!=NULL){
		fseek(fp,-1,SEEK_END);
		fprintf(fp, "%d\n", s->roll);
		fprintf(fp, "%s\n", s->name);
		fprintf(fp, "%s\n", s->branch);
		fprintf(fp, "%d\n", s->semester);
		fprintf(fp, "%d\n", s->no_of_course);
		for(int i=1;i<=(s->no_of_course);i++){
			fprintf(fp, "%s\n", s->course[i-1]);
		}
		fprintf(fp , "\n\n");
		s = s->next_student;
	}
	fclose(fp);
}

void show_all_student(){
	struct student * s = first_student;
	while(s!=NULL){
		show_student(s);
		s = s->next_student;
	}
}

void show_student(struct student * s){
		printf("Roll : %d\n", s->roll);
		printf("Name : %s\n", s->name);
		printf("Branch : %s\n", s->branch);
		printf("Semester : %d\n", s->semester);
		printf("Courses : \n\t");
		for(int i=0;i<(s->no_of_course);i++)
			printf("%s  ", s->course[i]);
		printf("\n\n");
}

void display_student(int roll){
	struct student * s = first_student;
	while(s!=NULL && s->roll != roll)
		s = s->next_student;
	if(s == NULL)
		printf("The roll doesn\'t exists \n");
	else show_student(s);
}

void load_instructor_data(){	// loading all the instructor data to list from txt file
	FILE * fp1 , * fp2;
	fp1 = fopen("instructor_file.txt", "a+");
	fp2 = fopen("instructor_file.txt", "a+");
	int i;
	while(fscanf(fp1,"%d",&i)!=-1){		// While an integer(id number) is successfully read
		fseek(fp1,ftell(fp2),SEEK_SET);	// seek back to read the id again
		create_instructor_profile(-1);
		struct instructor * s = first_instructor;
		while(s->next_instructor!= NULL)
			s = s->next_instructor;
	fscanf(fp1,"%d",&(s->id));
	fscanf(fp1," %s",(s->name));
	fscanf(fp1," %d",&(s->no_of_course));
		s->course = (char **)calloc(s->no_of_course,sizeof(char *));
		for(int i=0;i<(s->no_of_course);i++){
			s->course[i] = (char *)calloc(MAX,sizeof(char ));
			fscanf(fp1,"%s",s->course[i]);
		}
		fseek(fp2,ftell(fp1),SEEK_SET);	// move reference pointer to the end of the current instructor details
	}
}

void modify_instructor(int id, char c){
	struct instructor *s2, *s1, *s = first_instructor;
	while(s->next_instructor!=NULL && s->id!=id)
		s = s->next_instructor;
	if(s->id != id){
		printf("The id doesn't exists \n");
		return ;
	}
	if(c == 'm')	// if instructor details is to be updated 
		update_instructor_profile(s, id);

	else {		// if instructor profile is to be deleted 
		if(first_instructor->id == id){	// if the profile to be deleted is starting item
			s = first_instructor;
			first_instructor = first_instructor->next_instructor;
		}
		else {		// profile to be deleted lies somewhere in between 
			s1 = first_instructor;
			while(s1 -> next_instructor != s)	// find parent node to the node of profile to be deleted
				s1 = s1->next_instructor;
			s1->next_instructor = s->next_instructor;
		}
		free(s);
	}

}

void create_instructor_profile(int id){
struct instructor *s2, * s1 = (struct instructor *)calloc(1, sizeof(struct instructor));
	if(first_instructor==NULL){
		first_instructor=s1;
		return ;
	}
	s2 = first_instructor;
	while(s2->next_instructor!=NULL){
		if(s2->id == id){
			printf("The instructor already exists\n");
			return ;
		}
		s2= s2->next_instructor;
	}
	s2->next_instructor=s1;
}
void update_instructor_profile(struct instructor * s, int id){
	s->id = id;

	printf("enter instructor first name : \n");
	scanf(" %s",(s->name));

	printf("enter no of courses : \n");
	scanf(" %d",&(s->no_of_course));

	s->course = (char **)calloc(s->no_of_course,sizeof(char *));
	for(int i=0;i<(s->no_of_course);i++){
		printf("Enter course %d : \n",i+1);
		s->course[i] = (char *)calloc(MAX,sizeof(char ));
		scanf("%s",s->course[i]);
	}
}	
 void update_instructor_file(){	// saving all the changes to the txt file 
	FILE * fp = fopen("instructor_file.txt","w+");
	struct instructor * s = first_instructor;
	while(s!=NULL){
		fseek(fp,-1,SEEK_END);
		fprintf(fp, "%d\n", s->id);
		fprintf(fp, "%s\n", s->name);
		fprintf(fp, "%d\n", s->no_of_course);
		for(int i=1;i<=(s->no_of_course);i++){
			fprintf(fp, "%s\n", s->course[i-1]);
		}
		fprintf(fp , "\n\n");
		s = s->next_instructor;
	}
	fclose(fp);
}

void show_all_instructor(){
	struct instructor * s = first_instructor;
	while(s!=NULL){
		show_instructor(s);
		s = s->next_instructor;
	}
}
