// Longest subarray with sum k

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &arr, long long k)
{
    int n = arr.size(); // size of the array.
    int len = 0;
    for (int i = 0; i < n; i++)
    { // starting index
        for (int j = i; j < n; j++)
        { // ending index
            // add all the elements of
            // subarray = arr[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++)
            {
                s += arr[K];
            }
            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

// Method -> 2 :
int longestSubArrayWithSumK(vector<int> &arr, long long k)
{
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

// Method -> 3 :
int longestSubarray(vector<int> arr, long long k)
{
    int left = 0, right = 0;
    long long sum = arr[0];
    int maxLen = 0;
    int n = arr.size();
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
            sum += arr[right];
    }
    return maxLen;
}
// Time complexity -> O(2*n)
// Space complexity -> O(1)

int main()
{
    vector<int> arr = {2, 3, 5, 1, 9, 4, 3, 3, 2, 2};
    long long k = 10;
    int len = getLongestSubarray(arr, k);
    cout << "The length of the longest subarray is : " << len << endl;

    int res = longestSubArrayWithSumK(arr, k);
    cout << "The length of the longest subarray is : " << res << endl;

    int res1 = longestSubArrayWithSumK(arr, k);
    cout << "The length of the longest subarray is : " << res1 << endl;
    return 0;
}