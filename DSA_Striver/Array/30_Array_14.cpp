// Set Matrix Zeroes -> suppose arr[i][j] = 0 then make all the elements of the ith row and jth columnn of the matrix to be zero

#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &matrix, int n, int m, int i)
{
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int n, int m, int j)
{
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        // Time complexity for this nested loop is O(n * m)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
                // Time complexity for these function is O(n + m)
            }
        }
    }
    // Overall,Time Complexity is O(n + m) * O(n * m)

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    // Time complexity for this nested loop is O(n * m)

    return matrix;
}
// Overall,Time complexity of whole function is O(n * m) * O(n+m) + O(n * m) -> O(n^3)

// Better Method
vector<vector<int>> zero_Matrix(vector<vector<int>> &matrix, int n, int m)
{

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        // Time Complexity for this nested loop is O(n * m)
        {
            if (matrix[i][j] == 0)
            {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        // Time Complexity for this nested loop is O(n * m)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}
// Overall,Time complexity for this better method is O(2 * n *m)
// Space Complexity is O(n) + O(m)

// Optimal Solution
vector<vector<int>> Optimalsol(vector<vector<int>> &matrix, int n, int m)
{

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    // vector<vector<int>> ans = zeroMatrix(matrix, n, m);
    vector<vector<int>> res = zero_Matrix(matrix, n, m);
    vector<vector<int>> Result = Optimalsol(matrix, n, m);


    cout << "The Final matrix is: n";
    // for (auto it : ans)
    // for (auto it : res)
    for (auto it : Result)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
