
#include<bits/stdc++.h>
#define size 11
using namespace std;

int table[size];

void init(){
    for(int i = 0; i < size; i++){
        table[i] = -1;
    }
}

void fold_int(string s){
    string a;
    int data = stoi(s);
    int sum = 0;
    for(int i = 0; i < s.length(); i+=3){
        a = s.substr(i,3);
        sum = sum + stoi(a);
    }
    int indx = sum%size;
    cout<<sum<<"*\n";
    table[indx] = data;
}

void display(){
    for(int i = 0; i < size; i++){
        cout<<"The "<<i<<"th element is "<<table[i]<<endl;;
    }
    cout<<endl;
}

int main(){

    int com;
    cout<<"Enter your command\n";
    string x;
    int item;
    while(1){
        cout<<"\tPress 1 to insert\n\tPress 2 to display list\n";
        cin>>com;
        switch (com){
        case 1:
            cout<<"Enter item :";
            cin>>x;
            fold_int(x);          
            break;
        case 2 :
            display();
            break;
        default:
            cout<<"Wrong command try again\n";
        }

    }
    return 0;
}
