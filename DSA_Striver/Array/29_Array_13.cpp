// Longest consecutive sequence

#include <bits/stdc++.h>
using namespace std;

// BrutForce Method
bool linearSearch(vector<int> &a, int num)
{
    int n = a.size(); // size of array
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size(); // size of array
    int longest = 1;
    // pick a element and search for its
    // consecutive numbers:
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int cnt = 1;
        // search for consecutive numbers
        // using linear search:
        while (linearSearch(a, x + 1) == true)
        {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}
// Time Complexity -> O(n^2)
// Space complexity -> O(1)

// Better Solution
int longest_Successive_Elements(vector<int> &arr)
{
    if (arr.size() == 0)
        return 0;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 == lastSmaller)
        {
            cnt += 1;
            lastSmaller = arr[i];
        }
        else if (lastSmaller != arr[i])
        {
            cnt = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}
// Optimal solution
// to be continue....

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence(BrutForce method) is " << ans << "\n";

    int res = longest_Successive_Elements(a);
    cout << "The longest consecutive sequence(Better method) is " << res << endl;
    return 0;
}
