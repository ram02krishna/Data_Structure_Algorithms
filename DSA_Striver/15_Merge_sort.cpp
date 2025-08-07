#include <bits/stdc++.h>
using namespace std;
// Merge Sort is to divide into two parts and merge them after sorted them.

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mS(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mS(arr, low, mid);
    mS(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr)
{
    mS(arr, 0, arr.size() - 1);
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time complexity is O(n*(log n to the base 2)) best,average and worst case.
// Space compelxity in the worst case is O(n)