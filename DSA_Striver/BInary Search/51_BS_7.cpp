// Find out how many times the array has been rotated

#include <bits/stdc++.h>
using namespace std;

// Brut Force Approach(using linear search)
int findKRotation(vector<int> &nums)
{
    int n = nums.size();
    int ans = INT_MAX;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < ans)
        {
            ans = nums[i];
            index = i;
        }
    }
    return index;
}
// Time complexity is O(n)
// Space complexity is O(1)

// Optimal Approach
int findK_Rotation(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[low] <= nums[high])
        {
            if (nums[low] < ans)
            {
                index = low;
                ans = nums[low];
            }
            break;
        }
        // if left part is sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] < ans)
            {
                index = low;
                ans = nums[low];
            }
            low = mid + 1;
        }
        else
        {
            // if right part is sorted
            if (nums[mid] < ans)
            {
                index = mid;
                ans = nums[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}
// Time complexity is O(log(n)) (to the base 2)

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    int ans1 = findK_Rotation(arr);
    cout << "The array is rotated :: " << ans1 << endl;
    return 0;
}