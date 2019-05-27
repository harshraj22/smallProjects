#include<stdio.h>
char pl1[10],pl2[10];
int matrix[5][6];
int add_matrix(int col, int val);
int set_matrix();
int show_matrix();
int check_matrix();
int check_col();
int check_row();
int check_diag_l();
int check_diag_r();
#define RAND_VAL 100

int main(int argc, char ** argv){
	int turn,j,k;
	set_matrix(); //sets the matrix with some random value(RAND_VAL in this case)

	printf("Enter the first names of first and second player :\n");
	scanf(" %s %s",pl1,pl2);
	printf("\n\n");
	printf("now enter the columns to be occupied [1-5] :\n");
	for(turn=0; ;turn++){
		turn%2==0?printf("%s\'s turn : \n",pl1):printf("%s\'s turn : \n",pl2);
		scanf(" %d",&k);
		if(add_matrix(k,turn%2)==0){
			printf("%10s wong selection , please reselect -\n","-");
			turn--;
		}
		show_matrix();
		printf("\n");
		k=check_matrix();	//checks if some player won
		if(k>=0){
                printf("Result : ");
			k==0?printf("%s won\n",pl1):printf("%s won\n",pl2);
			break;
		}
		else if(k==-2){
            printf("well played %s and %s . Game draw !\n",pl1,pl2);
            break;
            }
	}
	return 0;
}

int check_matrix(){
	int k=0;
	if(check_row()!=-1)
		return check_row();
	else if(check_col()!=-1)
		return check_col();
	else if(check_diag_l()!=-1)
		return check_diag_l();
	else if(check_diag_r()!=-1)
		return check_diag_r();
    for(int row=0;row<5;row++){
        for(int col=1;col<6;col++){
            if(matrix[row][col]==RAND_VAL)
                return -1;
        }
    }
	return -2;
}

int check_col(){
	for(int col=1;col<6;col++){
		for(int row=0;row<2;row++){
			int k= matrix[row][col]+matrix[row+1][col]+matrix[row+2][col]+matrix[row+3][col];
			if(k==0 || k==4){
				return k;
			}
		}
	}
	return -1;
}

int check_row(){
	for(int row=0;row<5;row++){
		for(int col=1;col<3;col++){
			int k=matrix[row][col]+matrix[row][col+1]+matrix[row][col+2]+matrix[row][col+3];
			if(k==0 || k==4){
				return k;
			}
		}
	}
	return -1;
}

int check_diag_l(){		//cheks if player won due to four consecutive matches in a diagonal
	for(int row=0;row<2;row++){
		for(int col=1;col<3;col++){
			int k=matrix[row][col]+matrix[row+1][col+1]+matrix[row+2][col+2]+matrix[row+3][col+3];
			if(k==0 || k==4){
				return k;
			}
		}
	}
	return -1;
}

int check_diag_r(){		//cheks if player won due to four consecutive matches in a diagonal ( the other way )
	for(int row =0;row < 2;row++){
		for(int col=5;col >3 ;col--){
			int k=matrix[row][col]+matrix[row+1][col-1]+matrix[row+2][col-2]+matrix[row+3][col-3];
			if(k==0 || k==4){
				return k;
			}
		}
	}
	return -1;
}


int show_matrix(){
	int row,col;
	for(row=0;row<5;row++){
		for(col=1;col<6;col++){
			if(matrix[row][col]==1)
				printf("%3.3s ",pl2);
			else if(matrix[row][col]==0)
				printf("%3.3s ",pl1);
			else printf("___ ");
		}
		printf("\n");
	}
	return 0;
}

int set_matrix(){
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++)
			matrix[i][j]=RAND_VAL;
	}
	return 0;
}

int add_matrix(int col, int val){
	if(col<1 || col>5)
		return 0;
	for(int row=4;row>=0;row--){
		if(matrix[row][col]==RAND_VAL){
			matrix[row][col]=val;
			return 1;
		}
	}
	return 0;
}
