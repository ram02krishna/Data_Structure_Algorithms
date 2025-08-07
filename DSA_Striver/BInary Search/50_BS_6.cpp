// Minimum in Rotated Sorted Array[Unique]
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array.

#include <bits/stdc++.h>
using namespace std;

// Naive Approach(Brut Force Approach)(Linear Search Algorithm)
int findmin(vector<int> &nums)
{
    int n = nums.size();
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, nums[i]);
    }
    return mini;
}
// Time complexity : O(n),n being the size of the array.
// Space complexity : O(1)

// Optimal Approach(using Binary search)

int findMin(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else
        { // if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}
// Time complexity is O(log n) to the base 2

//Further optimal approach
int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
} 

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findmin(arr);
    cout << "The minimum element is : " << ans << endl;

    int result = findMin(arr);
    cout << "The minimum element(optimal approach) is : " << result << endl;
    return 0;
}