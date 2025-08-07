// Implement Lower Bound
// The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
// The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

#include <bits/stdc++.h>
using namespace std;

// BruteForce Method
// Naive approach (Using linear search):

// Let’s understand how we can find the answer using the linear search algorithm. With the knowledge that the array is sorted, our approach involves traversing the array starting from the beginning. During this traversal, each element will be compared with the target value, x. The index, i, where the condition arr[i] >= x is first satisfied, will be the answer.

int Lower_Bound(vector<int> &nums, int x)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= x)
        {
            return i;
        }
    }
    return n; // If no index satisfies the condition, return the size of the array.
}
// Time Complexity: O(N), where N = size of the given array.
// Space Complexity: O(1) as we are using no extra space.

// Optimal Method(Binary search)
int LOWER_Bound(vector<int> &nums, int x)
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
// Time Complexity : O(log n) where n is the size of the array
// Space Complexity : O(1)

// Implement Upper Bound
// The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.
// The upper bound is the smallest index, ind, where arr[ind] > x.
// But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array. The main difference between the lower and upper bound is in the condition. For the lower bound the condition was arr[ind] >= x and here, in the case of the upper bound, it is arr[ind] > x.

// BruteForce Method (Linaer Search)
int Upper_Bound(vector<int> &nums, int x)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > x)
        {
            return i;
        }
    }
    return n; // If no index satisfies the condition, return the size of the array.
}
// Time Complexity is O(n) where n is the size of the array
// Space Complexity is O(1)

// Optimal Approach(Binary Search)
int UPPER_Bound(vector<int> &nums, int x)
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
// Time Complexity : O(log n) where n is the size of the array
// Space Complexity : O(1)

// Search Insert Position
// Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.
// If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.
// Example 1:
// Input Format: arr[] = {1,2,4,7}, x = 6
// Result: 3
// Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

// Example 2:
// Input Format: arr[] = {1,2,4,7}, x = 2
// Result: 1
// Explanation: 2 is present in the array and so we will return its index i.e. 1.

// This is can be done by the binary search
int SearchInsertPos(vector<int> &nums, int x)
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

// Floor and Ceil in the sorted array
// Floor -> Largest no. in the array <= x
// Ceil -> Smallest no. in the array >= x -> this is nothing but the lower bound case

// Example -> 1:
// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
// Result: 4 7
// Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

// Example -> 2:
// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
// Result: 8 8
// Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.

int findFloor(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] <= x)
        {
            ans = arr[mid];
            // look for smaller index on the left
            low = mid + 1;
        }
        else
        {
            high = mid - 1; // look on the right
        }
    }
    return ans;
}

int findCeil(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x)
        {
            ans = arr[mid];
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    int f = findFloor(arr, n, x);
    int c = findCeil(arr, n, x);
    return make_pair(f, c);
}
// Time Complexity: O(logN), where N = size of the given array.
// Reason: We are basically using the Binary Search algorithm.

// Space Complexity: O(1) as we are using no extra space.

int main()
{
    vector<int> nums = {2, 3, 5, 5, 6, 7, 7, 9, 11, 11, 11, 15};
    // Testing Lower Bound
    int x = 7;
    int ans = Lower_Bound(nums, x);
    cout << "The Lower Bound index is : " << ans << endl;

    int x1 = 16;
    int ans1 = LOWER_Bound(nums, x1);
    cout << "The LOWER BOUND index is : " << ans1 << endl;

    // Testing Upper Bound
    int x2 = 9;
    int ans2 = Upper_Bound(nums, x2);
    cout << "The Upper Bound index is : " << ans2 << endl;

    int ans3 = UPPER_Bound(nums, x2);
    cout << "The UPPER BOUND index is : " << ans3 << endl;

    // Edge Cases
    int x3 = 1;  // Less than smallest element
    int x4 = 20; // Greater than largest element
    cout << "Lower Bound for x = 1: " << LOWER_Bound(nums, x3) << endl;
    cout << "Upper Bound for x = 20: " << UPPER_Bound(nums, x4) << endl;

    int k = 8;
    int ind = SearchInsertPos(nums, k);
    cout << "The position where k should be inserted is : " << ind << endl;

    int arr1[] = {3, 4, 4, 7, 8, 10};
    int n1 = 6, y = 5;
    pair<int, int> answer = getFloorAndCeil(arr1, n1, y);
    cout << "The floor and ceil are: " << answer.first
         << " " << answer.second << endl;

    return 0;
}

// In STL,There are In-Built function for Upper Bound and Lower Bound that are upper_bound() and lower_bound()