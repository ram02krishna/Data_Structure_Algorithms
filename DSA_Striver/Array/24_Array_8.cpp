// Kadane's Algorithm : Maximum Subarray Sum In An Array

#include <bits/stdc++.h>
using namespace std;

// Maximum Subarray Sum
// Brute Force Method
int maxSubarraySum(int arr[], int n)
{
    int maxi = INT_MIN; // maximum sum
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // subarray = arr[i.....j]
            int sum = 0;
            // add all the elements of subarray:
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}
// Time complexity is O(n^3)
// Space complexity is O(1)

// Method -> 2: Better Method
// Method -> 2: Better Method
int MaxSubArraySum(int arr[], int n)
{
    int maxi = INT_MIN; // initialize maxi to the smallest possible value
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(maxi, sum); // update maxi inside the inner loop
        }
    }
    return maxi; // return the correct result
}

// Kadane's Algorithm
// Method -> 3 : Optimal Solution
long long Kadane(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    // if (maxi < 0) maxi = 0;

    return maxi;
}
// Time complexity for this algorithm is O(n)
// while Space complexity for this algoritm is O(1)

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    int MAXSum = MaxSubArraySum(arr, n);
    cout << "The maximum subarray sum using the better method is: " << MAXSum << endl;

    long long Result = Kadane(arr, n);
    cout << "The maximum subarray sum using optimal solution(kadane Algorithm) is : " << Result << endl;
    return 0;
}
