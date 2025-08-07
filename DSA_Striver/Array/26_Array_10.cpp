// Rearrange Array Elements by sign.
#include <bits/stdc++.h>
using namespace std;

// Brute Force :
vector<int> RearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
        else
        {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }
    return ans;
}
// Time complexity -> O(n)
// Space complexity -> O(n)
// In this case no of positive elements are equal to the no of negative elements.
// in this case if the nums array have the odd size then the last element will be left.

// so for this problem : if any of the positive and negative numbers are left then add them at the end without altering the order.
// if(no of pos. elements) > (no of neg. elements)
vector<int> alternateNumbers(vector<int> &arr)
{
    vector<int> pos, neg;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }
    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }
    return arr;
}
// Time Complexity -> O(n) + O(min(pos,neg)) + O(leftovers)  -> O(2 * n)
// Space Complexity -> O(n)

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> res = RearrangeArray(nums);
    cout << "Rearranged array: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    vector<int> arr = {3, 2, -3, 8, -15, 7, -2, 16, 25, 75};
    vector<int> result = alternateNumbers(arr);
    cout << "Rearranged array : ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
