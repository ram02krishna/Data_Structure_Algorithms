// Search element in Rotated Sorted Array - I

// How does the rotation occur in a sorted array?
// Let's consider a sorted array: {1, 2, 3, 4, 5}. If we rotate this array at index 3, it will become: {4, 5, 1, 2, 3}. In essence, we moved the element at the last index to the front, while shifting the remaining elements to the right.
// NOTE : Entire Array will have unique elements

#include <bits/stdc++.h>
using namespace std;

// BruteForce Approach(Linear Search)
// Using this method, we will traverse the array to find the location of the target value. If it is found we will simply return the index and otherwise, we will return -1

int index(vector<int> &arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
// Time complexity : O(n),n is the size of the array

// Optimal Approach(Binary Search)
int Search(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == k)
            return mid;

        // Check if the left half is sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= k && k < nums[mid])
                high = mid - 1; // Target is in the left half
            else
                low = mid + 1; // Target is in the right half
        }
        else
        {
            // Right half is sorted
            if (nums[mid] < k && k <= nums[high])
                low = mid + 1; // Target is in the right half
            else
                high = mid - 1; // Target is in the left half
        }
    }
    return -1; // Target not found
}

int main()
{
    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int target = 1;
    int result = index(nums, target);
    cout << "The Index of the target in the rotated sorted array : " << result << endl;

    int k = 8;
    int ans = Search(nums, k);
    cout << "The Index of the k in the rotated sorted array :  " << ans << endl;

    int k1 = 4;
    int ans1 = Search(nums, k1);
    cout << "The Index of the k in the rotated sorted array :  " << ans1 << endl;
    return 0;
}
