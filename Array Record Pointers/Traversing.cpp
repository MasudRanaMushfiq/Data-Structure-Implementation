#include<bits/stdc++.h>
using namespace std; 

int a[5] = {22, 45, 11, 55, 18};

int max(){
    

    int max;

    for(int i = 0; i < 5; i++){
        if(a[i]>a[0]){
            max = a[i];
        }
    }
    return max;
}

int min(){
  

    int min;

    for(int i = 0; i < 5; i++ ){
        if(a[i] < a[0]){
            min = a[i];
        }
    } 

    return min;
}

double avg(){
    
    
    double sum = 0;;
    
    for(int i = 0; i < 5; i++){
        sum = sum + (double)a[i] ;
    }

    double avg = sum/5;

    return avg;
}

int total(){
    
    
    int sum = 0;

    for(int i = 0; i < 5; i++){
        sum = sum + a[i];
    }

    return sum;
}

void sinValue(){

    for(int i = 0; i < 5; i++){
        int x = sin(a[i]);
        printf("Sin of %dth = %.4f\n", i+1, sin(a[i]));
    }
}

int main(){
    cout<<"Maximum is "<<max()<<endl;
    cout<<"Minimum is "<<min()<<endl;
    cout<<"Avarage is "<<avg()<<endl;
    cout<<"total is "<<total()<<endl;

    sinValue();

    return 0;
}


