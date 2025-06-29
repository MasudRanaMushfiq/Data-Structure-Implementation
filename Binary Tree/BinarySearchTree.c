#include <stdio.h>
#include <stdlib.h>

int insert(int* tree, int size, int element){
    if (tree == NULL)
        return 0;
    
    int pos = 0;
    while (pos < size)
    {
        if (tree[pos]> 0 && tree[pos] != element)
        {
            if (tree[pos] < element)
                pos = 2 * pos + 2;  
            else if (tree[pos] && tree[pos] > element)
                pos = 2 * pos + 1;  
        }
        else if(tree[pos] == element){
            printf("The node already exits at position %d \n", pos);
            return pos;
        }
        else
        {
            tree[pos] = element;
            return pos;
        }
    }
}

void print(int* tree, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", tree[i]);
    printf("\n");
}

int main()
{   
    printf("Initial Tree\n");
    
    int tree[100] = {0};
    const int tsize = 100;
    
    // print first 20 elements
    print(tree, 20);
    
    printf("Press 1 to insert node in BST and Press -1 to cancel \n");
    int x;
    while(1){
        int com;
        scanf("%d", &com);
        if(com == 1){
            printf("Node = ");  
            scanf("%d",&x);
            int pos = insert(tree, tsize, x);
            
            print(tree, pos+3);            
        }
        if(com == -1){
            break;
        }
    }

    
    return 0;
}
