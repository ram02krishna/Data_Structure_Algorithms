// Pascal's Triangle
/*

            1
          1   1
       1    2    1
     1   3    3   1
   1   4   6    4   1
 1  5    10  10   5  1

*/

// Logic -> Combination that is n C r that is equal to fac(n) / (fac(n) * fac(n-r))

#include <bits/stdc++.h>
using namespace std;

// To print the element of the nth row and rth column in the pascal triangle
int nCr(int n, int r)
{
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
// time complexity is O(r)
// space complexity is O(1)
int pascalTriangle(int r, int c)
{
    int element = nCr(r - 1, c - 1);
    return element;
}

// To print the nth row of the pascal's traiangle
void printNthRow(int n)
{
    long long ans = 1;  // The first element is always 1
    cout << ans << " "; // Print the first element

    // To print the rest of the elements of the nth row
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i) / i; // Correct formula to calculate the next element
        cout << ans << " ";
    }
    cout << endl;
}

// To print the pascal's Triangle
// Brut Force Solution
vector<vector<int>> pascal_Triangle(int n)
{
    vector<vector<int>> ans;

    // Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++)
        {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

// Optimal Solution

vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); // inserting the 1st element

    // calculate the rest of the elements:
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> Generate_pascalTriangle(int n)
{
    vector<vector<int>> ans;

    // store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: " << element << endl;

    int n = 5;
    cout << "The element of the nth row of the pascal Triangle are : " << endl;
    printNthRow(n);

    vector<vector<int>> ans = pascal_Triangle(n);
    cout << "Pascal's Triangle : " << endl;
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    vector<vector<int>> Pascal = Generate_pascalTriangle(n);
    cout << "Pascal's Triangle : " << endl;
    for (auto it : Pascal)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
