#include <bits/stdc++.h>
using namespace std;

// Convert adjacency matrix to adjacency list
vector<vector<int>> matrixToList(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}

// BFS
void bfs(int start, vector<vector<int>> &adjList, vector<bool> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Recursive DFS
void dfsRecursive(int node, vector<vector<int>> &adjList, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            dfsRecursive(neighbor, adjList, visited);
        }
    }
}

// Iterative DFS using stack
void dfsIterative(int start, vector<vector<int>> &adjList, vector<bool> &visited)
{
    stack<int> st;
    st.push(start);

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            visited[node] = true;
            cout << node << " ";

            // Push neighbors in reverse order for consistent output
            for (int i = adjList[node].size() - 1; i >= 0; i--)
            {
                int neighbor = adjList[node][i];
                if (!visited[neighbor])
                {
                    st.push(neighbor);
                }
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Convert matrix to adjacency list
    vector<vector<int>> adjList = matrixToList(matrix);

    vector<bool> visited(n, false);

    // BFS (Disconnected)
    cout << "\nBFS Traversal: ";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(i, adjList, visited);
        }
    }

    // DFS Recursive
    fill(visited.begin(), visited.end(), false);
    cout << "\nDFS Recursive Traversal: ";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsRecursive(i, adjList, visited);
        }
    }

    // DFS Iterative
    fill(visited.begin(), visited.end(), false);
    cout << "\nDFS Iterative Traversal: ";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsIterative(i, adjList, visited);
        }
    }

    return 0;
}