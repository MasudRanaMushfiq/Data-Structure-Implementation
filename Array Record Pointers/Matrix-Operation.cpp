#include<bits/stdc++.h>
using namespace std;

const int row = 3;
const int col = 3;

int mat1[row][col] = {{1,2,3},{3,4,5},{5,6,7}};
int mat2[row][col] = {{1,2,3},{3,4,5},{5,6,7}};

void addition(){

    int res[row][col];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int sum = mat1[i][j] + mat2[i][j];
            res[i][j] = sum;
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }  
}

void subtraction(){
    int res[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int sub = mat1[i][j] - mat2[i][j];
            res[i][j] = sub;
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void multiplication(){

    int res[row][col];

    for(int i = 0; i < row; i++){
         
        for(int j = 0; j < col; j++){
            res[i][j] = 0;
            for(int k = 0; k < col; k++)
                res[i][j]+= mat1[i][j]*mat2[i][j];
            
            cout<<res[i][j]<<" ";
        }

        cout<<endl;
    }
}

int main(){
    addition();
    cout<<"\n";
    
    subtraction();
    cout<<"\n";
    
    multiplication();
    cout<<"\n";
    
    return 0;
}