#include<stdio.h>

int main(int argc, char ** argv){	// user inputs the file name to be copied and the file destination as command line argument 
	FILE * fp1,*fp2;

	char *ch=argv[2],* var= argv[1];	// making a char pointer that stores the address along with the name of the file
	while(*ch!='\0')
		ch++;
	while(*var !='\0'){
		*ch=*var;
		ch++;
		var++;
	}
	*ch='\0';
	ch=argv[2];
	printf("%s",ch);


	fp1=fopen(("%s",argv[1]),"r");	// opening the file to be copied
	// fp2=fopen(("%s%s",argv[2],argv[1]),"w");	 	// doesn't work as ',' works as operator here , discarding the second part.
	fp2=fopen(ch,"w");	//creating and opwning file with same name at destination
	char c;
	while(fscanf(fp1,"%c",&c)!=-1){		// copying the file contents to the new file until EOF is encountered 
		fprintf(fp2,"%c",c);
	}
	fclose(fp1);
	fclose(fp2);

return 0;
}