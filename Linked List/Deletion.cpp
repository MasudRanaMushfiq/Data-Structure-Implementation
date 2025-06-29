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

bool delAtSpecific(nodeptr head, int pos){

    nodeptr ptr = head;
    if(ptr == NULL){
        return false;
    }
    cout<<"Deleting item at "<<pos<<"th position\n";
    nodeptr temp;
    while(--pos){
        temp = ptr;
        ptr = ptr->link;
    }

    temp->link = ptr->link;

    delete(ptr);

    return true;
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

    cout<<"Enter the position you want to delete from\n";

    int pos;
    cin>>pos;

   if(delAtSpecific(head, pos)){
        cout<<"Operation successful\n";
        display(head);
   }
    else cout<<"Operation failed\n"; 


    return 0;
}
