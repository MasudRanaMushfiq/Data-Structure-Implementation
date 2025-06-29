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

int searchList(nodeptr head, int item){
    
    nodeptr ptr = head;
    if(ptr == NULL){
        return -1;
    }
    int indx = 1;
    while(ptr != NULL){
        if(ptr->data == item){
            cout<<"Item found\n";
            return indx;
        }
        indx++;
        ptr = ptr->link;
    }
    return -1;
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

    cout<<"Enter the number you want to search\n";
    
    int item;
    cin>>item;

    int pos = searchList(head, item);

    if(pos){
        cout<<"position : "<<pos<<endl;
    }else{
        cout<<"Item Not found\n";
    }
   
    return 0;
}
