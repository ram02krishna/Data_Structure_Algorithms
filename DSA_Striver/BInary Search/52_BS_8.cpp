// Single Element in Sorted Array
// Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

// Example::
// Input Format:
//  arr[] = {1,1,2,2,3,3,4,5,5,6,6}
// Result:
//  4
// Explanation:
//  Only the number 4 appears once in the array.
#include <bits/stdc++.h>
using namespace std;

// Brute Force Method
int SingleElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1) // If there's only one element
        return nums[0];

    for (int i = 0; i < n; i++)
    {
        if (i == 0) // First element
        {
            if (nums[i] != nums[i + 1])
                return nums[i];
        }
        else if (i == n - 1) // Last element
        {
            if (nums[i] != nums[i - 1])
                return nums[i];
        }
        else // Middle elements
        {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                return nums[i];
        }
    }
    return -1; // Return -1 if no single element is found
}
// Time complexity is O(n)
// Space complexity is O(1)

// Another brute force method is XOR

// Optimal Approach

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // if arr[mid] is the single element:
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        {
            return nums[mid];
        }
        // we are in the left:
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {
            // eliminate the left half:
            low = mid + 1;
        }
        // we are in the right:
        else
        {
            // eliminate the right half:
            high = mid - 1;
        }
    }
    // dummy return statement:
    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7};
    int ans = SingleElement(nums);
    cout << "The single element in the sorted array by using brute force approach is: " << ans << endl;

    int res = singleNonDuplicate(nums);
    cout << "The single element in the sorted array by using brute force approach is (By Optimal Appproach): " << res << endl;
    return 0;
}
