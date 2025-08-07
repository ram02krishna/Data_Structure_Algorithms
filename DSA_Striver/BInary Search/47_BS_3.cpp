// Find the first and last occurence of a given number in the sorted array
// if the given number that is target is not found then return -1
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach (Linear Search)
pair<int, int> FirstAndLastIndex(vector<int> &nums, int x)
{
    int n = nums.size();
    int first = -1, last = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == x)
        {
            if (first == -1)
            {
                first = i;
                last = i;
            }
            last = i;
        }
    }
    return {first, last};
}
// Time complexity is O(n)
// Space complexity is O(1)

// Better Approach(Binary Search)
int LowerBound(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int UpperBound(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> FirstANDLastIndex(vector<int> &nums, int x)
{
    int lb = LowerBound(nums, x);
    int n = nums.size();
    if (lb == n || nums[lb] != x)
        return {-1, -1};
    return {lb, UpperBound(nums, x) - 1};
}
// Time complexity is 2 * O(log n)(to the base 2)
// Space complexity is O(1)

// Optimal Approach
int FirstOccurence(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return first;
}

int LastOccurence(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return last;
}

pair<int, int> FirstAndLastOccurence(vector<int> &nums, int k)
{
    int first = FirstOccurence(nums, k);
    if (first == -1)
        return {-1, -1};
    int last = LastOccurence(nums, k);
    return {first, last};
}

int count(vector<int> &arr, int x)
{
    pair<int, int> ans = FirstAndLastOccurence(arr, x);
    if (ans.first == -1)
        return 0;
    return (ans.second - ans.first + 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 3, 3, 3, 5, 5, 7, 9, 9};
    int x = 3;
    pair<int, int> result = FirstAndLastIndex(nums, x);

    cout << "First Index: " << result.first << endl;
    cout << "Last Index: " << result.second << endl;

    // Using Better Approach (Binary Search)
    pair<int, int> resultBinary = FirstANDLastIndex(nums, x);
    cout << "First Index (Binary Search): " << resultBinary.first << endl;
    cout << "Last Index (Binary Search): " << resultBinary.second << endl;

    // /Using Optimal Approach
    pair<int, int> result1 = FirstAndLastOccurence(nums, x);
    cout << "First Index (By using Optimal Approach) : " << result1.first << endl;
    cout << "Last Index (By using Optimal Approach) : " << result1.second << endl;

    int ans = count(nums, x);
    cout << "The number of occurrences is: " << ans << endl;

    return 0;
}
