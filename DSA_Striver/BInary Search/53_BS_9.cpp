// Find Peak Element in the array
// Problem Statement : Given an array of length N.Peak element is defined as the element greater than both of its neighbors.Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'.Find the index(0 - based) of a peak element in the array.If there are multiple peak numbers, return the index of any peak number.
// Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, the next element should be considered as negative infinity.

#include <bits/stdc++.h>
using namespace std;

// Brute Force Method (Linear Search)

int findPeakElement(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1]))
        {
            return i;
        }
    }
    return -1;
}
// Time Complexity : O(n) n being the size of the array
// Space Complexity : O(1)

// Optimal Solution(Binary Search)
int Find_Peak_Element(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;
    int low = 1, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((arr[mid] > arr[mid - 1]) && arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid] > arr[mid - 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
// Time complexity is O(log(n) ( to the base 2))
// Space complexity is O(1)  Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).

int main()
{
    vector<int> arr = {1, 2, 3, 4, 7, 9, 11, 8, 5};
    int PeakElement = findPeakElement(arr);
    cout << "The peak is at index : " << PeakElement << endl;

    int Res = Find_Peak_Element(arr);
    cout << "The peak is at index(by optimal approach) : " << PeakElement << endl;

    return 0;
}