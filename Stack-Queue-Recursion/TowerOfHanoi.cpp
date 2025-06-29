#include<bits/stdc++.h>
using namespace std;

void towerofHanoi(int n, char A, char B, char C){
    
    if (n == 0)
        return;
    
    towerofHanoi(n-1, A, B, C);
    cout<<"Move Disk " << n << " from "<< A <<" rod to "
    << C <<" rod "<< endl; 
    towerofHanoi(n-1, B, C, A);
}

int main(){
    int n;
    cout<<"Enter Number of disk in tower A : ";
    cin>>n;

    towerofHanoi(n, 'A', 'B', 'C');

    return 0;
}
