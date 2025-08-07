/*
Number of Subarrays with XOR K -> You will be given an array (let it be {4,2,2,6,4}) and k(let it be 6),then the number of subarrays with XOR as k = 6 are
1.{4,2} -> xor of 4 and 2 is 6(4 -> 100 and 2 -> 010 so xor of 100 and 010 is 110 which is 6)
2.{6} -> xor of single element is the the number itself
3.{2,2,6} -> xor of 2 and 2 is 0 and xor of 0 and 6 is 6 that is((2^2)^6) = 6
4.{4,2,2,6,4} -> ((((4^2)^2)^6)^4) = 6
*/

/* XOR truthtable
0 xor 0 -> 0
0 xor 1 -> 1
1 xor 0 -> 1
1 xor 1 -> 0 */

#include <bits/stdc++.h>
using namespace std;

// /BruteForce Method
int subarraysWithXorK(vector<int> a, int k)
{
    int n = a.size(); // size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            // step 2:calculate XOR of all
            //  elements:
            int xorr = 0;
            for (int K = i; K <= j; K++)
            {
                xorr = xorr ^ a[K]; // ^ is used for xor
            }

            // step 3:check XOR and count:
            if (xorr == k)
                cnt++;
        }
    }
    return cnt;
}
// Time complexity is O(n^3)
// Space Complexity is O(1)

// Better Solution
int SubarrayWithXorK(vector<int> arr, int k)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int xr = 0;
        for (int j = i; j < n; j++)
        {
            xr = xr ^ arr[j];
            if (xr == k)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
// Time complexity is O(n^2)
// Space complexity is O(1)

// Optimal Solution

int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    int k;
    cout << "Enter the value of k : " << endl;
    cin >> k;
    int ans = subarraysWithXorK(nums, k);
    cout << "The Number of Subarrays with XOR k is : " << ans << endl;
    int res = SubarrayWithXorK(nums, k);
    cout << "The Number of Subarrays with XOR k is : " << res << endl;
    return 0;
}