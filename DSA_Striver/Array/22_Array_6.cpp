// Sort an array of 0's,1's,2's

#include <bits/stdc++.h>
using namespace std;

void SORT(vector<int> &arr, int n)
{
    int cnt_0 = 0, cnt_1 = 1, cnt_2 = 2;
    for (int i = 0; i < n; i++) // time complexity -> O(n)
    {
        if (arr[i] == 0)
            cnt_0++;
        else if (arr[i] == 1)
            cnt_1++;
        else
            cnt_2++;
    }

    for (int i = 0; i < cnt_0; i++)
    {
        arr[i] = 0;
    }
    for (int i = cnt_0; i < cnt_0 + cnt_1; i++)
    {
        arr[i] = 1;
    }
    for (int i = cnt_0 + cnt_1; i < n; i++)
    {
        arr[i] = 2;
    }
    // These all three for loop will take time O(n)
}
// Time complexity = O(n) + O(n) = O(2n)
// Space complexity = O(1)

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr;
    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    return;
}

// Leave In between