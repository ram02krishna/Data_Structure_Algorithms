// Next Permutation
// Permutation -> no of ways the elements can be arranged
// such as we have given array [3 1 2]
// This array can be arranged as [1 2 3],[1 3 2],[2 1 3],[2 3 1],[3 1 2],[3 2 1]
// The next permutation of [1 3 2] is [2 1 3]
// This is something related to the dictionary

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A)
{
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1)
    {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--)
    {
        if (A[i] > A[ind])
        {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "]";
    return 0;
}
