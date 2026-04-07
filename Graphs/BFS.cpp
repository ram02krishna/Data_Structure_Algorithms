#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int V, vector<vector<int>> &adjMatrix)
{
    vector<int> bfs;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (int j = 0; j < V; j++)
                {
                    if (adjMatrix[node][j] == 1 && !visited[j])
                    {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }

    return bfs;
}

int main()
{
    vector<vector<int>> edgeList = {{0,1},{0,2},{1,2},{2,0},{2,3}};
    int n = 4;

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    for (int i = 0; i < edgeList.size(); i++)
    {
        int u = edgeList[i][0];
        int v = edgeList[i][1];

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // undirected graph,For directed graph, remove this line
    }

    vector<int> result = bfs(n, adjMatrix);

    for (auto x : result)
        cout << x << " ";

    return 0;
}