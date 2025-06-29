#include<bits/stdc++.h>
using namespace std;
#define size 11

int table[size];

// table = {54, 23, 21, 22};

// key = 10 --- 54
//key = 1 --- 23
//key = 0---21

void init(){
    for(int i = 0; i < size; i++){
        table[i] = -1;
    }
}
void insert(int value){
    int key = value % size;
    int indx;

    for(int i = 0; i < size; i++){
        indx = (key+i) % size;
        if(table[indx] == -1){
            table[indx] = value;
            break;
        }

        if(i == size-1){
            cout<<"Table full\n";
        }
    }
}

void search(int value){
    
    int key = value % size;
    int indx;

    for(int i = 0; i < size; i++){
        indx = (key+i)%size;
        if(table[indx] == value){
            cout<<"Item found\n";
            break;
        }
        if(i == size){
            cout<<"Item not found\n";
        }
    }
}
void display(){
    for(int i = 0; i < size; i++){
        cout<<i+1 <<"th element is "<<table[i]<<endl;
    }
    cout<<endl;
}

int main(){
    init();

    cout<<"Enter your command\n";
    int com;
    while(1){
        cout<<"\tPress 1 to insert item to hashtable\n\tPress 2 to search item on hashtable\n\tPress 3 to display the hash table\n\tPress 4 to quit program\n";
        cin>>com;
        switch (com)
        {
        case 1 :
            cout<<"Enter number to insert :";
            int x;
            cin>>x;
            insert(x);
            break;
        case 2 : 
            cout<<"Enter number to be searched :";
            int y;
            cin>>y;
            search(y);
            break;
        case 3 :
            display();
            break;
        case 4 :
            return 0;
        default:
            cout<<"Wrong command\n";
        }
    }

    return 0;
}
