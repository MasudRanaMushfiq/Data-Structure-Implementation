#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* link;
};

typedef struct Node* nodeptr;

void display(nodeptr head){
    nodeptr ptr = head;

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

void maxValue(nodeptr head){

    nodeptr ptr = head;

    if(ptr == NULL){
        cout<<"Empty List\n";
    }
    else{
        int max = INT_MIN;
        while(ptr != NULL){
            
            if(ptr->data > max){
                max = ptr->data;
            }
            ptr = ptr->link;
        }
        cout<<"Maximum value "<<max<<endl;
    }
}
void minValue(nodeptr head){
    nodeptr ptr = head;

    if(ptr == NULL){
        cout<<"Empty List\n";
    }
    else{
        int min = INT_MAX;
        while(ptr != NULL){
            
            if(ptr->data < min){
                min = ptr->data;
            }
            ptr = ptr->link;
        }
        cout<<"Minimum value "<<min<<endl;
    }

}

void Avarage(nodeptr head, int size){
    nodeptr ptr = head;

    if(ptr == NULL){
        cout<<"Empty List\n";
    }
    else{
        double sum = 0;
        double avg;
        while(ptr != NULL){
            sum = sum + double(ptr->data);
            ptr = ptr->link;
        }
        double s = double(size);
        avg = sum/s;
        cout<<"Avarage Value "<<avg<<endl;
    }
}

void totalValue(nodeptr head){
    
    nodeptr ptr = head;
    if(ptr == NULL){
        cout<<"Empty list\n";
    }
    else{
        int sum = 0;
        while(ptr != NULL){
            sum = sum + ptr->data;
            ptr = ptr->link; 
        }
        cout<<"Total value "<<sum<<endl;
    }
}

void sinValue(nodeptr head){
    
    nodeptr ptr = head;
    if(ptr == NULL){
        cout<<"List Empty\n";
    }
    else{
        while(ptr != NULL){
            double x = double(ptr->data);
            double degree = x*(3.1416/180);
            double result = sin(degree);
            cout<<"Sin of "<< ptr->data << " is "<<result<<endl;
            ptr = ptr->link;
            
        }
    }
}

int main(){

    cout<<"Enter size of the list\n";
    
    int size;
    cin>>size;
    int Listsize = size;
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
    size++;

    display(head);
    maxValue(head);
    minValue(head);
    Avarage(head,Listsize);
    totalValue(head);
    sinValue(head);
    return 0;
}
