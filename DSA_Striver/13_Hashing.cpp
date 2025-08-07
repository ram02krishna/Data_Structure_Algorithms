/*
#include <bits/stdc++.h>
using namespace std;

// int hash[1000000] = {0};
// int hash[10000000] = {0};
int main()
{
    // Part 1: Handling integer array and counting occurrences
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int hash[13] = {0}; // Limiting the array to 13 (0-12)
    // int hash[100000] = {0};
    // int hash[1000000] = {0};
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0 && arr[i] < 13) // Ensure no out-of-bounds access
            hash[arr[i]] += 1;
        else
            cout << "Warning: Array element out of hash array bounds!" << endl;
    }

    cout << "Enter the number of queries for array elements: " << endl;
    int q;
    cin >> q;
    cout << "Enter the elements whose count you want to know:" << endl;
    while (q--)
    {
        int number;
        cin >> number;
        if (number >= 0 && number < 13)
            cout << "Count of " << number << " is: " << hash[number] << endl;
        else
            cout << "Number " << number << " is out of bounds!" << endl;
    }
    // Time complexity is O(n*n)

    // If you initialise the hash array at the index 10^7 inside the int main then this will show you the segmentation error for the integer values as after index 10^6 it will give you segmentation error.
    // But you declare hash array at same index globally that is outside int main then this will not give you error.It will give you error when you declare hash array at the index after 10^7.
    // Same for boolean,if u declare till index 10^7 inside int main then no segmentation error but after 10^7 it will show u segmentation error.

    // Part 2: Handling string and counting character occurrences
    string s;
    cout << "Enter a string: " << endl;
    cin >> s;

    // Pre-compute frequency of characters ('a' to 'z')
    int char_hash[26] = {0};
    // int char_hash[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z') // Validating character range
            char_hash[s[i] - 'a']++;
    }

    cout << "Enter the number of queries for characters: " << endl;
    cin >> q;
    while (q--)
    {
        char c;
        cout << "Enter character to query: " << endl;
        cin >> c;
        if (c >= 'a' && c <= 'z')
            cout << "Count of '" << c << "' is: " << char_hash[c - 'a'] << endl;
        else
            cout << "Character '" << c << "' is out of bounds!" << endl;
    }

    return 0;
}
*/

// Using map save the memory/storage as it only stores the queries elements which we want to know the counts of those queries elements.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    int n;
    cout << "Enter the size of the array : " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array :: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // pre-compute
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }

    // int q;
    // cout << "Enter the number of queries : " << endl;
    // cin >> q;
    // while (q--)
    // {
    //     int number;
    //     cin >> number;
    //     // fetch
    //     cout << "Count of '" << number << "' is: " << mpp[number] << endl;
    // }

    // use it or use map iteration for print the ouput of number of queries
    // Time complexity in this case is O(n*log(n))
    */

    int n;
    cout << "Enter the size of the array : " << endl;
    cin >> n;
    char arr[n];
    cout << "Enter the elements of the array :: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // pre-compute
    // map<char, int> mpp;
    unordered_map<char, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }

    // Time complexity for storing and fetching in the unordered map is O(1) for the best and average case,and O(n) for the worst case where n is no of elements in map

    return 0;
}

// Hashing is designed by using these methods
// 1.Division method
// 2.Folding method
// 3.Mad squaring method
// For this Try to search Array Hashing on google.