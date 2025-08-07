// By Jagdish Sir

#include <stdio.h>
#include <limits.h>
#define V 5

int G[5][5] = {
    {0, 10, 3, 0, 0},
    {0, 0, 1, 2, 0},
    {0, 4, 0, 8, 2},
    {0, 0, 0, 0, 7},
    {0, 0, 0, 9, 0},
};

int min_distance_el(int d[], int visited[])
{
    int min = INT_MAX, index = -1;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0 && d[i] < min)
        {
            min = d[i];
            index = i;
        }
    }
    return index;
}

void djikstra(int s)
{
    int d[V], visited[V];
    for (int i = 0; i < V; i++)
    {
        d[i] = INT_MAX;
        visited[i] = 0;
    }
    d[s] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = min_distance_el(d, visited);
        visited[u] = 1;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && G[u][v] && d[u] != INT_MAX && G[u][v] + d[u] < d[v])
            {
                d[v] = d[u] + G[u][v];
            }
        }
    }

    printf("\nShortest Paths\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t %d\n", i, d[i]);
    }
}

int main()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    djikstra(0);
}