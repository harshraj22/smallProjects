#include <bits/stdc++.h>
using namespace std;
int row=10,column=10;
vector<vector<float> > matrix(row+1,vector<float> (column+1,0.0));
vector<float> coeff(row+1,0.0),solution(row+1,0.0);
inline int update_matrix();
inline int convert_into_ref();
inline int edit_matrix(int col,int first_elem);
inline int update_row(int rw,float mult_fact,int col,int first_elem);
inline int show_matrix();
inline int find_first_elem(int col);
inline int check_sol();
inline int find_sol();
inline int solve(int rw,int col);
inline int fix_matrix();
inline int display();


int main(){
    int i,j;
    cout<<"Welcome user ! Press 1 if you want to read manual before using it (It is advisable to read ) else Press 0\n";
    cin>>i;
    if(i==1)
        display();
    cout<<"\n\n\t\t-----------------The program starts----------------------\n\n";

    cout<<"Enter number of rows and columns\n";
    cin>>row>>column;
    matrix.resize(row+1,vector<float> (column+1,0.0));
    coeff.resize(row+1);
    solution.resize(column+1,0);
    cout<<"Now please enter the elements\n";
    for(i=1;i<=row;i++){
        for(j=1;j<=column;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"now enter coefficients\n";
    for(i=1;i<=row;i++)
        cin>>coeff[i];

    update_matrix();
    convert_into_ref();
    show_matrix();

    if(check_sol)
        find_sol();
    for(i=1,cout<<"\n\n";i<=column;i++)
        cout<<solution[i]<<" ";
    cout<<"\n\n";
    main();

return 0;
}

inline int display(){
string s = R"(                          Hello !
This basic programme has been built to find the solutions for given number of equations and variables .

You are expected to first tell the number of equatins (denoted by rows here) and number of variables (denoted by columns here)
and then the constant terms (denoted by coefficients here ).

The program will first print the augmented matrix in Row Echelon Form , and then print the values of corresponding variables if 
solution exists.Note that for a given matrix , there can be more than one way of representing in ROW ECHELON FORM.
Also Note that , In case of infinite solutions , the programm will output that set of solution in which values of free variables is zero .

This programm hasn't been designed keeping the time complexity in mind , hence you are "expected not to give too many equations and 
variables and equations . Also you are not expected to use too large integer values .
)";

cout<<s<<endl;

return 0;
}

inline int update_matrix(){
    int i,j;
    float sum=0.0;
    for(i=1;i<=row;i++){
        for(j=1;j<=column;j++){
            sum+=abs(matrix[i][j]);     //use std accumulate in algorithms library
        }
        matrix[i][0]=sum;
        sum=0;
    }

    for(i=1;i<=column;i++){
        for(j=1;j<=row;j++){
            sum+=abs(matrix[j][i]);     //use std accumulate in algorithms library
        }
        matrix[0][i]=sum;
        sum=0;
    }
return 0;
}

inline int convert_into_ref(){
    int i,first_elem=0,top_element=1;
    for(i=1;i<=column;i++){
        if(matrix[0][i]!=0){    //i.e. a non-zero column
            first_elem=max(top_element,find_first_elem(i));

        if(first_elem!=top_element){
            matrix[top_element].swap(matrix[first_elem]);
            swap(coeff[top_element],coeff[first_elem]);
            edit_matrix(i,top_element); // to make i-th column
                }
            top_element++;
        }
        /*
        cout<<i<<"\n";
        show_matrix();
        cout<<"\n\n";
        */

    }
    update_matrix();
return 0;
}

inline int find_first_elem(int col){
    int i;
    for(i=row;i>0;i--){
        if(matrix[i][col]!=0)   //std find
            return i;
    }
return 0;
}

inline int edit_matrix(int col,int first_elem){
    int i;
    float mult_fact;
    for(i=first_elem+1;i<=row;i++){
            if(matrix[i][col]!=0){
                mult_fact=matrix[i][col]/matrix[first_elem][col];
                update_row(i,mult_fact,col,first_elem);
        }
    }
    update_matrix();
return 0;
}

inline int update_row(int rw,float mult_fact,int col,int first_elem){
    int i;
    for(i=col;i<=column;i++){
        matrix[rw][i]=matrix[rw][i]-matrix[first_elem][i]*mult_fact;
    }
    coeff[rw]=coeff[rw]-coeff[first_elem]*mult_fact;
    fix_matrix();
return 0;
}

inline int show_matrix(){
    int i,j;
    for(i=1;i<=row;i++){
        for(j=1;j<=column;j++){
            cout<<fixed<<setprecision(6)<<matrix[i][j]<<"  ";
        }
        cout<<"\t"<<coeff[i]<<"\n";
    }
return 0;
}

inline int check_sol(){
    int i,j;
    for(i=1;i<=row;i++){
        if(matrix[i][0]==0 && coeff[i]!=0)  //sum=0 doesn't emply every element is zero
            return 0;
    }
return 1;
}

inline int find_sol(){
    int i,j;
    for(i=row;i>0;i--){
        for(j=1;j<=column;j++){
            if(matrix[i][j]!=0){
                solve(i,j);
                break;
            }
        }
    }
return 0;
}

inline int solve(int rw,int col){
    float sum=0;
    int i;
    for(i=col+1;i<=column;i++)
        sum=sum+matrix[rw][i]*solution[i];
    solution[rw]=(coeff[rw]-sum)/matrix[rw][col];
return 0;
}

inline int fix_matrix(){
    int i,j;
    for(i=1;i<=row;i++){
        for(j=1;j<=column;j++){
            if(abs(matrix[i][j])<0.001)
                matrix[i][j]=0;
        }
    }
return 0;
}

