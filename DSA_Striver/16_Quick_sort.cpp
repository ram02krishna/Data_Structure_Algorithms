#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (arr[i] <= pivot && i <= high)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quicksort(vector<int> arr)
{
    qs(arr, 0, arr.size() - 1);
    return arr;
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

    vector<int> sortedArr = quicksort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Quick Sort has the time complexity O(n * log(n)) and space complexity O(1)

// Algorithm -> Pick a pivot(let it be the first element of the array)and place it in its correct place inside in the counted array.Now compare it with the other elements and place them that is smaller one to the left of pivot and larger one to the right of the pivot.
// Example -> arr[] => 4 6 2 5 7 9 1 3
// using insertion sort, pivot => arr[1] = 4
// now on comparison other elements => 2 1 3 4 6 5 7 9
//  2 1 3 are placed left of pivot that is 4 and 6 5 7 9 are placed right of pivot.we have compared other elements with the pivot starting from index 1 to the index n.
// let take the smaller elements and consider it a individual array
