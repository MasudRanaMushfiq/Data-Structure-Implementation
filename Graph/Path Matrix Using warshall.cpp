#include <stdio.h>
#define N 4

void printMatrix(int matrix[N][N]);
void warshall(int graph[N][N], int closure[N][N]);

int main() {
   
    printf("Enter adjacency matrix \n");
    int graph[N][N];
    int x;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &x);
            graph[i][j] = x;
        }
    }
    int transitiveClosure[N][N];

    warshall(graph, transitiveClosure);

    printf("Path Matrix:\n");
    printMatrix(transitiveClosure);

    return 0;
}
void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void warshall(int graph[N][N], int closure[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            closure[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
            }
        }
    }
}
