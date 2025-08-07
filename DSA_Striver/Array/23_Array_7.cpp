// Majority Elements -> Elements that appear more than n/2 times

#include <bits/stdc++.h>
using namespace std;

// Brute Force Method
int Majority(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 0; // Reset count for each element
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                cnt++;
            }
        }
        if (cnt > n / 2)
        {
            return arr[i]; // Return if the count exceeds n/2
        }
    }
    return -1; // Return -1 if no majority element is found
}

// Better Method (Using Hashing)
int majority(vector<int> &arr, int n)
{
    map<int, int> mpp; // Time complexity -> O(n log(n))
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++; // Increment the count for each element
    }
    for (auto it : mpp)
    { // Time complexity -> O(n)
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }
    return -1; // Return -1 if no majority element is found
}
// Total Time complexity -> O(n * log(n)) + O(n)
// Space complexity -> O(n)

// MOORE'S VOTING ALGORITHM
int majorityElement(vector<int> arr)
{
    int cnt = 0;
    int e; // Initialize e with a default value
    for (int i = 0; i < arr.size(); i++)
    {
        if (cnt == 0)
        {
            e = arr[i]; // Update the candidate element
            cnt = 1;    // Reset count for the new candidate
        }
        else if (arr[i] == e)
        {
            cnt++; // Increment count if the same candidate is found
        }
        else
        {
            cnt--; // Decrement count if a different element is found
        }
    }

    // Final check for the candidate
    cnt = 0; // Reset count to verify the candidate
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == e)
        {
            cnt++;
        }
    }
    if (cnt > arr.size() / 2)
    {
        return e; // Return the majority element
    }
    return -1; // Return -1 if no majority element is found
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = Majority(arr, n);
    cout << "The element that appears more than n/2 (Brute Force) is: " << result << endl;

    int result_1 = majority(arr, n);
    cout << "The element that appears more than n/2 (Hashing) is: " << result_1 << endl;

    int result_2 = majorityElement(arr);
    cout << "The element that appears more than n/2 (Moore's Voting) is: " << result_2 << endl;

    return 0;
}
