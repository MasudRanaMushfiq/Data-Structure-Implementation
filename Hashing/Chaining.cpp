#include<bits/stdc++.h>
using namespace std;
#define size 11

struct node{
    int data;
    struct node* next;
};
struct node *chain[size];

void init(){
    for(int i = 0; i < size; i++){
        chain[i] = NULL;
    }
}

void insert(int value){

    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    int key = value % size;

    if(chain[key] == NULL){
        chain[key] = newNode;
    }
    else{
        struct node* temp = chain[key];
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }

}

void search(int value){

    int key = value % size;
    struct node* temp = chain[key];
    while(temp != NULL){
        if(temp->data == value){
            cout<<"Item found\n";
            return;
        }
        temp = temp->next;
    }
    cout<<"Item not found\n";
    
}

void display(){

    for(int i = 0; i < size; i++){
        struct node* temp = chain[i];
        while(temp != NULL){
            cout<<temp->data<<"--->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
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
