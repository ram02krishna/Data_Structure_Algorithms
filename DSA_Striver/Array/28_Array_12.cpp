// Leaders in an array -> Everything in the right of the element should be smaller than that element
#include <bits/stdc++.h>
using namespace std;

// Brute Force method
void Leader(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    bool leader;
    for (int i = 0; i < n; i++)
    {
        leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                leader = false;
                break;
            }
        }
        if (leader == true)
        {
            ans.push_back(arr[i]);
        }
    }

    cout << "Leaders: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
// Time complexity -> O(n^2)
//  Space complexity -> O(n)

// Optimal solution
//  Back Traversal
vector<int> superiorElements(vector<int> &arr)
{
    int n = arr.size();
    int maxi = INT_MIN;
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {7, 6, 9, 2, 11, 6, 4, 8, 5, 1, 3};

    Leader(arr); // Calling the Leader function (if needed)

    vector<int> res = superiorElements(arr);

    cout << "Superior elements : " << endl;
    for (int it : res)
        cout << it << " ";
    return 0;
}
