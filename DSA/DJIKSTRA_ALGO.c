#include <stdio.h>
#include <limits.h> // For INT_MAX

#define MAX 100     // Maximum number of vertices
#define INF INT_MAX // Infinity value to represent unreachable distances

// Function to find the shortest path using Dijkstra's algorithm
void dijkstra(int graph[MAX][MAX], int n, int src, int dest)
{
    int dist[MAX];    // Array to store the shortest distance from the source to each vertex
    int visited[MAX]; // Array to mark whether a vertex has been processed
    int parent[MAX];  // Array to store the parent of each vertex in the shortest path

    // Initialize all distances as INF and all vertices as unvisited
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;  // Set distance to all vertices as infinity
        visited[i] = 0; // Mark all vertices as unvisited
        parent[i] = -1; // Initialize parent array as -1 (no parent)
    }

    dist[src] = 0; // Distance from source to itself is always 0

    // Process all vertices
    for (int count = 0; count < n - 1; count++)
    {
        int min = INF, u;

        // Find the vertex with the minimum distance value among unvisited vertices
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && dist[v] <= min)
            {
                min = dist[v];
                u = v;
            }
        }

        visited[u] = 1; // Mark the selected vertex as visited

        // Update distance values of the adjacent vertices of the selected vertex
        for (int v = 0; v < n; v++)
        {
            // Update dist[v] only if:
            // 1. v is not visited
            // 2. There is an edge from u to v
            // 3. Distance to u is not INF
            // 4. The new distance through u is smaller than the current distance to v
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v]; // Update the distance
                parent[v] = u;                   // Update the parent of v to u
            }
        }
    }

    // Check if the destination is reachable
    if (dist[dest] == INF)
    {
        printf("No path exists from %d to %d.\n", src, dest);
        return;
    }

    // Print the minimum cost from source to destination
    printf("Minimum cost from %d to %d is %d\n", src, dest, dist[dest]);

    // Reconstruct the path using the parent array
    printf("Path: ");
    int stack[MAX], top = -1; // Stack to store the path in reverse order
    int curr = dest;          // Start from the destination
    while (curr != -1)
    {
        stack[++top] = curr; // Push current vertex to the stack
        curr = parent[curr]; // Move to the parent vertex
    }
    while (top >= 0)
    {
        printf("%d ", stack[top--]); // Pop vertices from the stack to print the path
    }
    printf("\n");
}

int main()
{
    int graph[MAX][MAX]; // Adjacency matrix to represent the graph
    int n, src, dest;    // Number of vertices, source vertex, and destination vertex

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (use 0 for no direct connection):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the source and destination vertices
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    printf("Enter the destination vertex: ");
    scanf("%d", &dest);

    // Call the Dijkstra function to find the shortest path
    dijkstra(graph, n, src, dest);

    return 0;
}

/*
Input -> 
Enter the number of vertices: 5
Enter the adjacency matrix (use 0 for no direct connection):
0 10 0 30 100
0 0 50 0 0
0 0 0 0 10
0 0 20 0 60
0 0 0 0 0
Enter the source vertex: 0
Enter the destination vertex: 4


Output ->
Minimum cost from 0 to 4 is 60
Path: 0 3 2 4


Graph Representation:
Vertices: 0, 1, 2, 3, 4

Edges (with weights):
0 → 1 (weight: 10)
0 → 3 (weight: 30)
0 → 4 (weight: 100)
1 → 2 (weight: 50)
3 → 2 (weight: 20)
3 → 4 (weight: 60)
2 → 4 (weight: 10)

Graph Structure:
    0
   /|\ 
 10 | 30 
 /  |   \
1   |   3
 \  |  / \
  50| /   60
   2 -----> 4
     \____/
      (10)


*/