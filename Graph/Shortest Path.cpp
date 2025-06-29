#include <stdio.h>
#include <limits.h>

// Define the number of vertices in the graph
#define V 4
#define inf INT_MAX

// Function to perform the Floyd-Warshall algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    
    // Initialize the distance matrix with the graph values
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Applying the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Printing the shortest path distances
    printf("Shortest path distances between all pairs of nodes:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the adjacency matrix\n");
    int graph[V][V];
    int x;
    
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
          scanf("%d",&x);
          graph[i][j] = x;  
        }
    }

    floydWarshall(graph);

    return 0;
}
