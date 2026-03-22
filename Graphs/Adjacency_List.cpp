#include <bits/stdc++.h>
using namespace std;

void print_graph(unordered_map<int, vector<int>> &adjList)
{
    for (auto it : adjList)
    {
        cout << it.first << "->";
        for (int i = 0; i < it.second.size(); i++)
        {
            cout << it.second[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> edgeList = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};
    unordered_map<int, vector<int>> adjList;
    for (int i = 0; i < edgeList.size(); i++)
    {
        int u = edgeList[i][0];
        int v = edgeList[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u); // for undirected graph
    }
    print_graph(adjList);
    return 0;
}