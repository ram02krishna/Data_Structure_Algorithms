#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adjMatrix, vector<int> &visited, vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);

    for (int i = 0; i < adjMatrix[node].size(); i++)
    {
        if (adjMatrix[node][i] == 1 && !visited[i])
        {
            dfs(i, adjMatrix, visited, ans);
        }
    }
}

int main()
{
    vector<vector<int>> edgeList = {{0,1}, {0,2}, {1,2}, {2,0}, {2,3}};
    int n = 4;

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    // Build adjacency matrix
    for (int i = 0; i < edgeList.size(); i++)
    {
        int u = edgeList[i][0];
        int v = edgeList[i][1];

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // undirected graph
    }

    vector<int> visited(n, 0);
    vector<int> ans;

    dfs(0, adjMatrix, visited, ans);

    cout << "DFS Traversal: ";
    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}