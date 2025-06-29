#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int key;
    struct node *left, *right;
};
 

struct node* newNode(int item){
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key){
    
    if (node == NULL)
        return newNode(key);
 
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else if(key == node->key){
      cout<<"Element already exits\n";
    }
    return node;
}
void printTree(struct node* node){
    if (node == NULL)
        return;
 
    
    printTree(node->left);
 
    // Then recur on right subtree
    printTree(node->right);
 
    // Now deal with the node
    cout<<node->key<<" ";
}


int main() {
  struct node* root = nullptr;
  int com ;
  int x;
  while(1){
    cout<<"Press 1 to insert data\nPress 2 to display\nPress 3 to quit\n";
    cin>>com;
    switch (com)
    {
    case 1:
      cout<<"Enter number :";
      cin>>x;
      root = insert(root, x);
      break;
    case 2:
      printTree(root);
      cout<<endl;
      break;
    case 3:
        cout<<"Good Bye!!\n";
        return 0;
      
    }
  }
  return 0;
}
