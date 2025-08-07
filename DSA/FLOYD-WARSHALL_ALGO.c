#include <stdio.h>
#define INF 99999 // Represents infinity

void floydWarshall(int graph[][100], int V)
{
    int dist[100][100];

    // Initialize the solution matrix same as the input graph matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0; // Distance to itself is 0
            }
            else if (graph[i][j] != 0)
            {
                dist[i][j] = graph[i][j]; // Use the input graph value if there is an edge
            }
            else
            {
                dist[i][j] = INF; // Set distance to infinity if no edge exists
            }
        }
    }

    // Apply Floyd-Warshall Algorithm
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("%7s", "INF");
            }
            else
            {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int V; // Number of vertices
    int graph[100][100];

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, V);

    return 0;
}
