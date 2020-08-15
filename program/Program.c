#include<stdio.h>
#include<stdlib.h>		// for calloc and realloc
#include<string.h>		// used strcpy , strcmp : check_course_availability()
#include <signal.h> 	// for signal handling

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
    char **instructor_ids;
    struct course * next_course;

};

struct student * first_student;		// can't be declared as a const , as the first node might be needed to be deleted 
struct instructor * first_instructor;
struct course * first_course;

void load_student_data();	// taking data from txt file to linked list
int create_student_profile(int roll);	// adding node to linked list
void update_student_profile(struct student * s, int roll);	// adding values to the newly node
void update_student_file();	// adding all student nodes to txt file
void show_all_student();
void display_student(int roll);
void show_student(struct student * s);
void modify_student(int roll, char c);

void load_instructor_data();	// taking data from txt file to linked list
int create_instructor_profile(int id);	// adding node to linked list
void update_instructor_profile(struct instructor * s, int id);	// adding values to the newly node
void update_instructor_file();	// adding all instructor nodes to txt file
void show_all_instructor();
void display_instructor(int id);
void show_instructor(struct instructor * s);
void modify_instructor(int id, char c);

void load_course_data();	// taking data from txt file to linked list
int create_course_profile(int code );
void update_course_profile(struct course * s, int roll);	// adding values to the newly node
void update_course_file();	// adding all student nodes to txt file
void show_all_course();
void display_course(int code);
void show_course(struct course * s);
void modify_course(int code, char c);
void check_course_availability(char * s);	// checks if the entered course is stored in list of courses 

void sigintHandler(int sig_num);


int main(){
load_student_data();
load_instructor_data();
load_course_data();

int i,j,roll,id,code;

signal(SIGINT, sigintHandler);	// https://www.geeksforgeeks.org/write-a-c-program-that-doesnt-terminate-when-ctrlc-is-pressed/
while(1){
	printf("\n\v Options : \n\t 1 : student\t 2 : instructor\t 3 : course\t 4 : End \n\n Your choise :  ");
	scanf("%d",&i);
	switch(i){
		case 1 :{
			printf("\n Options : \n\t 1 : Display all\t 2 : Display particular\t 3 : Add\t 4 : Delete\t 5 : Modify\n Your choise :  ");
			scanf("%d",&j);
			switch(j){
				case 1:
					show_all_student();
					break;

				case 2:
					printf("Enter roll\n");
					scanf("%d",&roll);
					display_student(roll);
					break;

				case 3:
					printf("Enter roll\n");
					scanf("%d",&roll);
					if(create_student_profile(roll)){
						struct student * s = first_student;
						while(s->next_student!=NULL)
							s = s->next_student;
						update_student_profile(s, roll);	
					}
					break;
				case 4:
					printf("Enter roll\n");
					scanf("%d",&roll);	
					modify_student(roll,'d');
					break;		
				case 5:
					printf("Enter roll\n");
					scanf("%d",&roll);	
					modify_student(roll,'m');
					break;
				default:
					printf("wrong selection\n");				
			}
			break;
		}
		case 2:{
			printf("\n Options : \n\t 1 : Display all\t 2 : Display particular\t 3 : Add\t 4 : Delete\t 5 : Modify\n Your choise :  ");
			scanf("%d",&j);
			switch(j){
				case 1:
					show_all_instructor();
					break;

				case 2:
					printf("Enter id\n");
					scanf("%d",&id);
					display_instructor(id);
					break;

				case 3:
					printf("Enter id\n");
					scanf("%d",&id);
					if(create_instructor_profile(id)){
						struct instructor * s = first_instructor;
						while(s->next_instructor!=NULL)
							s = s->next_instructor;
						update_instructor_profile(s, id);	
					}
					break;
				case 4:
					printf("Enter id\n");
					scanf("%d",&id);	
					modify_instructor(id,'d');
					break;		
				case 5:
					printf("Enter id\n");
					scanf("%d",&id);	
					modify_instructor(id,'m');
					break;
				default:
					printf("wrong selection\n");				
			}
			break;
		}
		case 3:{
			printf("\n Options : \n\t 1 : Display all\t 2 : Display particular\t 3 : Add\t 4 : Delete\t 5 : Modify\n Your choise :  ");
			scanf("%d",&j);
			switch(j){
				case 1:
					show_all_course();
					break;

				case 2:
					printf("Enter code\n");
					scanf("%d",&code);
					display_course(code);
					break;

				case 3:
					printf("Enter code\n");
					scanf("%d",&code);
					if(create_course_profile(code)){
						struct course * s = first_course;
						while(s->next_course!=NULL)
							s = s->next_course;
						update_course_profile(s, code);	
					}
					break;
				case 4:
					printf("Enter code\n");
					scanf("%d",&code);	
					modify_course(code,'d');
					break;		
				case 5:
					printf("Enter code\n");
					scanf("%d",&code);	
					modify_course(code,'m');
					break;
				default:
					printf("wrong selection\n");				
			}
			break;
		}
		case 4:
			update_student_file();	// for saving the updated data to the corresponding file
			update_instructor_file();
			update_course_file();
			printf("\v\v %10c Thank you for using the programme . %c \n",'-','-');
			return 0;
	}

}
	update_student_file();
	update_instructor_file();
	update_course_file();
	return 0;
}

/* Signal Handler for SIGINT, This makes sure that update data is saved before
the programme is terminated. */
void sigintHandler(int sig_num){ 
    /* Reset handler to catch SIGINT next time. 
       Refer http://en.cppreference.com/w/c/program/signal */
    signal(SIGINT, sigintHandler); 
    printf("\n Cannot be terminated using Ctrl+C. Please use the provided methods only. \n"); 
    fflush(stdout); 
} 

//--------------------------------------------------------end of signal handling--------------------------------------------------

void load_student_data(){	// loading all the student data to list from txt file
	FILE * fp1 , * fp2;
	fp1 = fopen("student_file.txt", "a+");
	fp2 = fopen("student_file.txt", "a+");
	int i;
	while(fscanf(fp1,"%d",&i)!=-1){		// While an integer(roll number) is successfully read
		fseek(fp1,ftell(fp2),SEEK_SET);	// seek back to read the roll again
		create_student_profile(-1);		// adding one more student to the list
		struct student * s = first_student;
		while(s->next_student!= NULL)	// going to the end node of the list to update(modify) the values of newly added student node
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
	if(c == 'm')	// if strudent details is to be updated(modify)
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

int create_student_profile(int roll){
struct student *s2, * s1 = (struct student *)calloc(1, sizeof(struct student));
	if(first_student==NULL){
		first_student=s1;
		return 1;			// the function returns 1 on successful creation of the student's profile
	}
	s2 = first_student;
	while(s2->next_student!=NULL){
		if(s2->roll == roll){
			printf("The student already exists\n");
			return 0;
		}
		s2= s2->next_student;
	}
	if(s2->roll == roll){		// checking for the last node of the list
		printf("The student already exists\n");
		return 0;
	}
	s2->next_student=s1;
	return 1;
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
		check_course_availability(s -> course[i]);		// to give the user a hint if the entered course doesn't exist
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
		printf("\n");
		printf("Roll : %d\n", s->roll);
		printf("Name : %s\n", s->name);
		printf("Branch : %s\n", s->branch);
		printf("Semester : %d\n", s->semester);
		printf("Courses : \n\t");
		for(int i=0;i<(s->no_of_course);i++)
			printf("%s  ", s->course[i]);
		printf("\n");
}

void display_student(int roll){
	struct student * s = first_student;
	while(s!=NULL && s->roll != roll)
		s = s->next_student;
	if(s == NULL)
		printf("The roll doesn\'t exists \n");
	else show_student(s);
}

//----------------------------------------------end of student related functions--------------------------------------------------------------------------------

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
		for(int i=0;i< (s -> no_of_course);i++){
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

int create_instructor_profile(int id){
struct instructor *s2, * s1 = (struct instructor *)calloc(1, sizeof(struct instructor));
	if(first_instructor==NULL){
		first_instructor=s1;
		return 1;			// 1 returned on successful creation of new node (instructor profile)
	}
	s2 = first_instructor;
	while(s2->next_instructor!=NULL){
		if(s2->id == id){
			printf("The instructor already exists\n");
			return 0;
		}
		s2= s2->next_instructor;
	}
	if(s2->id == id){
		printf("The instructor already exists\n");
		return 0;
	}
	s2->next_instructor=s1;
	return 1;
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
		check_course_availability(s -> course[i]);
	}
	printf("\n");
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

void show_instructor(struct instructor * s){
		printf("\n");
		printf("id : %d\n", s->id);
		printf("Name : %s\n", s->name);
		printf("Courses : \n\t");
		for(int i=0;i<(s->no_of_course);i++)
			printf("%s  ", s->course[i]);
		printf("\n");
}

void display_instructor(int id){
	struct instructor * s = first_instructor;
	while(s!=NULL && s->id != id)
		s = s->next_instructor;
	if(s == NULL)
		printf("The id doesn\'t exists \n");
	else show_instructor(s);
}

//-------------------------End of Instructor related functions ---------------------------------------------------------------------------------------------------


int create_course_profile(int code ){
	struct course * c = first_course;
	if(first_course == NULL){
		first_course = (struct course *)calloc(1, sizeof(struct course));
		first_course -> code = code;
		return 1;
	}
	while(c -> next_course != NULL){
		if(c -> code == code){
			printf("The given code already exists\n");
			return 0;
		}
		c = c -> next_course;
	}
	if(c -> code == code){
		printf("The given code already exists\n");
		return 0;
	}
	c -> next_course = (struct course *)calloc(1, sizeof(struct course));
	c = c -> next_course;
	c -> code = code;
	return 1;
}

void load_course_data(){	// loading all the course data to list from txt file
	FILE * fp1 , * fp2;
	fp1 = fopen("course_file.txt", "a+");
	fp2 = fopen("course_file.txt", "a+");
	int i;
	while(fscanf(fp1,"%d",&i)!=-1){		// While an integer(course code number) is successfully read
		fseek(fp1,ftell(fp2),SEEK_SET);	// seek back to read the course code again
		create_course_profile(-1);		// adding one more node at the end of the linked list
		struct course * s = first_course;
		while(s->next_course!= NULL)
			s = s->next_course;
	fscanf(fp1,"%d",&(s->code));
	fscanf(fp1," %s",(s->name));
	fscanf(fp1," %d",&(s->credits));
	fscanf(fp1," %d",&(s->no_of_instructors));
		s->instructor_ids = (char **)calloc(s->no_of_instructors,sizeof(char *));
		for(int i=0;i<(s->no_of_instructors);i++){
			s->instructor_ids[i] = (char *)calloc(MAX,sizeof(char ));
			fscanf(fp1,"%s",s->instructor_ids[i]);
		}
		fseek(fp2,ftell(fp1),SEEK_SET);	// move reference pointer to the end of the current student details
	}
}

void update_course_profile(struct course * s, int code){
	s->code = code;

	printf("enter course name : \n");
	scanf(" %s",(s->name));

	printf("enter credits : \n");
	scanf(" %d",&(s-> credits));

	printf("enter no of instructors : \n");
	scanf(" %d",&(s->no_of_instructors));

	s->instructor_ids = (char **)calloc(s->no_of_instructors,sizeof(char *));
	for(int i=0;i<(s->no_of_instructors);i++){
		printf("Enter instructor ID %d : \n",i+1);
		s->instructor_ids[i] = (char *)calloc(MAX,sizeof(char ));
		scanf("%s",s->instructor_ids[i]);
	}
	printf("\n");
}

 void update_course_file(){	// saving all the changes to the txt file 
	FILE * fp = fopen("course_file.txt","w+");
	struct course * s = first_course;
	while(s!=NULL){
		fseek(fp,-1,SEEK_END);
		fprintf(fp, "%d\n", s->code);
		fprintf(fp, "%s\n", s->name);
		fprintf(fp, "%d\n", s->credits);
		fprintf(fp, "%d\n", s->no_of_instructors);
		for(int i=1;i<=(s->no_of_instructors);i++){
			fprintf(fp, "%s\n", s->instructor_ids[i-1]);
		}
		fprintf(fp , "\n\n");
		s = s->next_course;
	}
	fclose(fp);
}


void show_all_course(){
	struct course * s = first_course;
	while(s!=NULL){
		show_course(s);
		s = s->next_course;
	}
}

void show_course(struct course * s){
		printf("\n");
		printf("code : %d\n", s->code);
		printf("Name : %s\n", s->name);
		printf("credits : %d\n", s->credits);
		printf("instructors : \n\t");
		for(int i=0;i<(s->no_of_instructors);i++)
			printf("%s  ", s->instructor_ids[i]);
		printf("\n");
}

void display_course(int code){
	struct course * s = first_course;
	while(s!=NULL && s->code != code)
		s = s->next_course;
	if(s == NULL)
		printf("The course doesn\'t exists \n");	/* symbol escaping using \ */
	else show_course(s);
}

void modify_course(int code, char c){
	struct course *s2, *s1, *s = first_course;
	while(s->next_course!=NULL && s -> code != code)
		s = s -> next_course;
	if(s -> code != code){
		printf("The code doesn't exists \n");
		return ;
	}
	if(c == 'm')	// if course details is to be updated 
		update_course_profile(s, code);

	else {		// if course profile is to be deleted 
		if(first_course -> code == code){	// if the profile to be deleted is starting item
			s = first_course;
			first_course = first_course -> next_course;
		}
		else {		// profile to be deleted lies somewhere in between 
			s1 = first_course;
			while(s1 -> next_course != s)	// find parent node to the node of profile to be deleted
				s1 = s1->next_course;
			s1->next_course = s->next_course;
		}
		free(s);
	}

}

void check_course_availability(char * s){		// checks if the entered course is stored in list of courses 
	struct course *c = first_course;
	while(c != NULL){
		if(strcmp(s,c->name)==0)
			return ;
		c = c-> next_course;
	}
	// in case the given course isn't found 
	printf("The given course doesn't exist in the database. Created a random one with code -1 , please modify accordingly .\n");
	c = first_course;
	if(c != NULL){
		while(c -> next_course != NULL)
			c= c-> next_course;
	c -> next_course = (struct course *)calloc(1,sizeof(struct course));
	c = c->next_course;	
	}
	else {
		c = (struct course *)calloc(1,sizeof(struct course));	
	}

	c -> code = -1;			// negative course code to diffrentiate from normal codes 
	strcpy(c -> name, s);	// the course should be created with same name 
	c -> credits = 007;		// random initialisation of unregistered course
	c -> no_of_instructors =0;
}

//---------------------------End of course related functions-----------------------------------------------------------------------------------------------------------------------


