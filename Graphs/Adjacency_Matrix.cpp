#include <bits/stdc++.h>
using namespace std;

void print_graph(vector<vector<int>> &adjMatrix)
{
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        for (int j = 0; j < adjMatrix[i].size(); j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> edgeList = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};
    int n = 4;
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    for (int i = 0; i < edgeList.size(); i++)
    {
        int u = edgeList[i][0];
        int v = edgeList[i][1];
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // for undirected graph
    }
    print_graph(adjMatrix);
    return 0;
}