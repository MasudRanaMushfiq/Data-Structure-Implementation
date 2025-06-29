#include<bits/stdc++.h>
using namespace std;

int main(){

    cout<<"Enter the Number of vertices\n";
    int numNodes;
    cin>>numNodes;

    int A[numNodes][numNodes];
    cout<<"Enter the Adjacancy matrix\n";

    int MAT[numNodes][numNodes][numNodes];// for later use
    for(int i = 0; i < numNodes; i++){
        for(int j = 0; j < numNodes; j++){
            cin>>A[i][j];
            MAT[0][i][j] = A[i][j];
        }
    }

    //a) adjacent of V1, V2, ....,Vm;

    for(int i = 0; i < numNodes; i++){
        for(int j = 0; j < numNodes; j++){
            if(A[i][j] == 1){
                cout<<(i+1)<<"th node has direct path to "<<(j+1)<<"th node\n";
            }
        }
    }
    cout<<endl;
    //b, c and d
    int var[numNodes][numNodes];
    for(int l = 0; l < numNodes-1; l++){
        for(int i = 0; i < numNodes; i++){
            for(int j = 0; j < numNodes; j++){
                var[i][j] = 0;

                for(int k = 0; k < numNodes; k++){
                    var[i][j] += MAT[l][i][k] * MAT[0][k][j]; 
                }
                MAT[l+1][i][j] = var[i][j];
            }
        }        
    }
    
 

    for(int l = 1; l < numNodes; l++){
        int cnt = 0;
        for(int i = 0; i < numNodes; i++){
            for(int j = 0; j < numNodes; j++){
                if(MAT[l][i][j] > 0){
                    cnt++;
                }
            }
        }
        cout<<"N0. of path of length "<<l+1<<" is "<<cnt<<"\n";
    }

    return 0;
}
