// Count subarray sum equals k
#include <bits/stdc++.h>
using namespace std;

// BrutForce Method
int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // Calculate the sum of subarray [i...j]
            int sum = 0;
            for (int K = i; K <= j; K++)
                sum += arr[K];

            // If sum equals k, increase the count and print the subarray
            if (sum == k)
            {
                cnt++;
                cout << "Subarray with sum " << k << ": ";
                for (int K = i; K <= j; K++)
                    cout << arr[K] << " ";
                cout << endl;
            }
        }
    }
    return cnt;
}
// Time complexity in this case is somewhat O(n^3)

// Better method
int count(vector<int> &arr, int k)
{
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum == k)
            {
                cnt++;
                cout << "Sub Array With Sum : " << k << " : ";
                for (int k = i; k <= j; k++)
                    cout << arr[k] << " ";
                cout << endl;
            }
        }
    }
    return cnt;
}
// Time complexity is O(n^2)

// Optimal Solution
// By using prefix solution
//  We will use hashmap data structure -> presum is the key and the value will be cnt
// Initially we have (presum,cnt) => (0,1)

int findAllSubarraysWithSumEqualToK(vector<int> &arr, int k) {
    int n = arr.size(); // size of the given array.
    unordered_map<int, int> mpp; // Use unordered_map for O(1) average time complexity
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Initialize the map with the prefix sum of 0.

    for (int i = 0; i < n; i++) {
        // Add the current element to the prefix sum:
        preSum += arr[i];

        // Calculate the prefix sum we need to remove:
        int remove = preSum - k;

        // Add the number of times 'remove' has appeared in the map to count:
        if (mpp.find(remove) != mpp.end()) {
            cnt += mpp[remove];
        }

        // Update the count of the current prefix sum in the map:
        mpp[preSum]++;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {1, 2, 3, 5, 6, 7, 1, 2, 4, 6, 8, 11, 9, 1, 16, 2, 4, 5};
    int k = 11;
    int result = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays whose sum is equal to " << k << " is " << result << endl;
    cout << endl;
    int res = count(arr, k);
    cout << "The number of subarrays whose sum is equal to " << k << " is " << res << endl;
    int cnt = findAllSubarraysWithSumEqualToK(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}
