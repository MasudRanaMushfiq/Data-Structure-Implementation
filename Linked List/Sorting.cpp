#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* link;
};

typedef struct Node* nodeptr;

void display(nodeptr ptr){
    if(ptr == NULL){
        cout<<"Empty list\n";
    }
    
    else{
        while(ptr != NULL){
            cout<<ptr->data<<" ";
            ptr = ptr->link;
        }
        cout<<endl;
    }
}

void sortList(nodeptr head){

    nodeptr current = head;

    if(current == NULL){
        cout<<"List is Empty\n";
    }
    else{
        nodeptr ptr = NULL;
        while(current != NULL){
            ptr = current->link;
            int temp;
            while(ptr != NULL){
                if(ptr->data < current->data){
                    temp = current->data;
                    current->data = ptr->data;
                    ptr->data = temp;        
                }
                ptr = ptr->link;
            }
            current = current->link;
        }
    }
}

int main(){

    cout<<"Enter size of the list\n";
    
    int size;
    cin>>size;

    cout<<"Enter elements of the list\n";

    int first;
    cin>>first;

    nodeptr head = (nodeptr)malloc(sizeof(nodeptr));
    head->data = first;
    head->link = NULL;

    nodeptr ptr = head;
    size--;

    while(size--){
        int x;
        cin>>x;

        nodeptr current = (nodeptr)malloc(sizeof(nodeptr));
        current->data = x;
        current->link = NULL;

        ptr->link = current;
        ptr = ptr->link;
    }

    display(head);
    cout<<"Sorted list :\n";

    sortList(head);
    display(head);
    

    return 0;
}
