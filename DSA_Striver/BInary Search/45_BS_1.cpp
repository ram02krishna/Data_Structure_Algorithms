// Binary Search Introduction
// Binary search is applicable only in the sorted area
// Splits into two halves

#include <bits/stdc++.h>
using namespace std;

// Iterative version
int binarySearch(vector<int> &nums, int target)
{
    int n = nums.size(); // size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
// Time complexity is O(log n) (to the base 2)

// Recursive Version
int binarySearch(vector<int> &nums, int low, int high, int target)
{

    if (low > high)
        return -1; // Base case.

    // Perform the steps:
    int mid = (low + high) / 2;
    if (nums[mid] == target)
        return mid;
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    return binarySearch(nums, low, mid - 1, target);
}

int search(vector<int> &nums, int target)
{
    return binarySearch(nums, 0, nums.size() - 1, target);
}
// Time Complexity for the recursive method is log(n) (base is 2)
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = binarySearch(a, target);
    if (ind == -1)
        cout << "The target is not present." << endl;
    else
        cout << "The target is at index: "
             << ind << endl;

    int ind = search(a, target);
    if (ind == -1)
        cout << "The target is not present." << endl;
    else
        cout << "The target is at index: "
             << ind << endl;

    return 0;
}
