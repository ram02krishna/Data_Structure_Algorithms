#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> combination;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1, 1); // Start each row with 1s
            if (i > 1)
            { // Start filling from the third row onwards
                for (int j = 1; j < i; j++)
                {
                    row[j] = combination[i - 1][j - 1] + combination[i - 1][j];
                }
            }
            combination.push_back(row); // Add the current row to the triangle
        }
        return combination;
    }
};

int main()
{
    Solution solution;
    int numRows;

    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;

    vector<vector<int>> pascalTriangle = solution.generate(numRows);

    cout << "Pascal's Triangle:" << endl;
    for (const auto &row : pascalTriangle)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
