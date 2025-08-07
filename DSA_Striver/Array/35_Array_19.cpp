// Majority Element[ > n/3 ]

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v)
{
    int n = v.size(); // size of the array
    vector<int> ls;   // list of answers

    for (int i = 0; i < n; i++)
    {
        // selected element is v[i]:
        //  Checking if v[i] is not already
        //  a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i])
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                // counting the frequency of v[i]
                if (v[j] == v[i])
                {
                    cnt++;
                }
            }
            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2)
            break;
    }

    return ls;
}
// Time complexity -> O(n^2)
// Space Complexity -> O(1)

// Better Solution
// Hashing

vector<int> majority_Element(vector<int> v)
{
    int n = v.size(); // size of the array
    vector<int> ls;   // list of answers

    // declaring a map:
    map<int, int> mpp;

    // least occurrence of the majority element:
    int mini = int(n / 3) + 1;

    // storing the elements with its occurnce:
    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;

        // checking if v[i] is
        //  the majority element:
        if (mpp[v[i]] == mini)
        {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2)
            break;
    }

    return ls;
}
// Time Complexity is O(n) * O(1)
// Space Complexity is O(n)

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    vector<int> result = majority_Element(arr);
    cout << "The Majority elements are : ";
    for (auto it : result)
        cout << it << " ";
    cout << endl;
    return 0;
}