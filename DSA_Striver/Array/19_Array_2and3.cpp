#include <bits/stdc++.h>
using namespace std;
/*
// Function to find the missing number between 1 to n
// Method->1(BruteForce Method): Linear search
int Missing(const vector<int> &arr, int n)
{
    unordered_set<int> numSet(arr.begin(), arr.end());

    for (int i = 1; i <= n; i++)
    {
        if (numSet.find(i) == numSet.end())
        {
            return i; // Return the missing number
        }
    }
    return -1; // In case no number is missing (this should not happen for valid input)
}
// Time complexity is O(n*n)
// Space complexity is O(1)

// Method->2(Better Method): Hashing
int Missing_value(vector<int> &arr, int n)
{
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
}

// Method->3(Optimal Method)
int Missing_Element(vector<int> &arr, int n)
{
    int sum = (n * (n + 1)) / 2;
    int s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s2 += arr[i];
    }
    return (sum - s2);
}
// Time complexity -> O(n)
// Space complexity -> O(1)

// Method->4(XOR Method)
int XOR(vector<int> &arr, int n)
{
    int XOR1 = 0;
    for (int i = 1; i < n; i++)
    {
        XOR1 = XOR1 ^ i;
    }
    int XOR2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        XOR2 = XOR2 ^ arr[i];
    }
    return XOR1 ^ XOR2;
}
// Time Complexity -> O(n)
// Space complxity -> O(1)
*/

/*
// Maximum consecutive Ones
int findMaxConsecutiveOnes(vector<int> &arr, int n)
{
    int maxi = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else
        {
            cnt = 0;
        }
    }
    return maxi;
}
*/
// Find the number that appears once and other number twice
int once(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            return num;
        }
    }
}
// Time complexity -> O(n^2)
// Space complexity -> O(1)

// Hashing Method
int hashing(vector<int> &arr, int n)
{
    unordered_map<int, int> hash; // Using a map for better memory management

    // Count the occurrences of each element
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    // Find the first unique element
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
        {
            return arr[i];
        }
    }

    return -1; // Return -1 or some value to indicate no unique element
}
// XOR Method
int getSingleElement(vector<int> &arr)
{
    int xorr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    /*
    int miss = Missing(arr, n);
    if (miss != -1)
    {
        cout << "The missing number is : " << miss << endl;
    }
    else
    {
        cout << "No missing number found." << endl;
    }
    cout << endl;

    int result = Missing_value(arr, n);
    if (result != -1)
    {
        cout << "The missing number is : " << result << endl;
    }
    else
    {
        cout << "No missing number found." << endl;
    }
    cout << endl;

    int another_method = Missing_Element(arr, n);
    if (another_method != -1)
    {
        cout << "The missing number is : " << another_method << endl;
    }
    else
    {
        cout << "No missing number found." << endl;
    }
    cout << endl;

    int XOR_method = XOR(arr, n);
    if (XOR_method != -1)
    {
        cout << "The missing number is : " << XOR_method << endl;
    }
    else
    {
        cout << "No missing number found." << endl;
    }
    cout << endl;
    */

    // int result = findMaxConsecutiveOnes(arr, n);
    // cout << "Maximum no of consecutive ones found in an array : " << result << endl;

    int result_1 = once(arr, n);
    cout << "Number that appears once and others twice is : " << result_1 << endl;

    int hash_result = hashing(arr, n);
    cout << "Number that appears once and others twice by using hashing method is : " << hash_result << endl;

    int res = getSingleElement(arr);
    cout << "Number that appears once and othesr twice by using XOR method is : " << res << endl;
    return 0;
}
