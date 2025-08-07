// 2 Sum

#include <bits/stdc++.h>
using namespace std;

// Method -> 1:
bool two_sum(const vector<int> &arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) // Only check j > i to avoid duplicates
        {
            if (arr[i] + arr[j] == k)
            {
                return true; // Found a pair
            }
        }
    }
    return false; // No pairs found
}
// Time complexity -> O(n^2)
// Space complexity -> O(1)

// Method -> 2:
pair<int, int> twosum(const vector<int> &arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        { // Only check j > i to avoid duplicates
            if (arr[i] + arr[j] == k)
            {
                return {i, j}; // Return the indices of the pair
            }
        }
    }
    return {-1, -1}; // No pairs found, return an invalid index pair
}

// Method -> 3: HASHING
pair<int, int> Hashing(vector<int> &arr, int n, int k)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int moreNeeded = k - num;
        if (mpp.find(moreNeeded) != mpp.end())
        {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1}; // Indicating no pair found
}
// Time complexity -> O(n * log n) in the case of map and O(n) in the best case of unordered map and O(n^2) in the worst case of unordered map
// Space complexity -> O(n) in the case of map

// Method -> 4:
bool optimal_Method(vector<int> &arr, int n, int k)
{
    int left = 0, right = n - 1;
    sort(arr.begin(), arr.end());
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == k)
        {
            return "Yes";
        }
        else if (sum < k)
            left++;
        else
            right--;
    }
    return "No";
}
// Time complexity -> O(n) + O(n log(n)) -> for traversal + sorting(O(n log(n)))
// Space complexity -> O(1) (when u are not changing the array that is not sorting the array)
// But we are sorting the array which is changing the array.So,The space complexity becomes O(n)

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    int k;
    cout << "Enter the value of target that is k: ";
    cin >> k;

    bool result = two_sum(arr, n, k);
    cout << "Two Sum Found: " << (result ? "Yes" : "No") << endl;

    pair<int, int> result1 = twosum(arr, n, k);
    if (result1.first != -1)
    {
        cout << "Indices of the pair: " << result1.first << " and " << result1.second << endl;
    }
    else
    {
        cout << "No valid indices found." << endl;
    }

    pair<int, int> Result = Hashing(arr, n, k);
    cout << "Indices of the pair : " << Result.first << " and " << Result.second << endl;

    int Optimal_Result = optimal_Method(arr, n, k);
    cout << "The result of the optimal method : " << Optimal_Result << endl;

    return 0;
}
