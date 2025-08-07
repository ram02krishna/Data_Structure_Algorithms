#include <bits/stdc++.h>
using namespace std;

// Max size of the array u can define is 10 to the power 6 that is (10^6)inside the int main.
// Whereas outside the int main that is globally,u can define the max. size of the array which is 10 to the power 7(10^7).
int largest(vector<int> &arr, int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}
/*
int second_largest(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int second_largest = arr.at(n - 2);
    return second_largest;
}
// This will take (n * log(n)) time complexity.


*/
int second_largest(vector<int> &arr, int n)
{
    int first = INT_MIN, second = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first)
        {
            second = arr[i];
        }
    }
    return second;
}
// This function will take O(n) time complexity which is less than O(n * log(n))

int second_smallest(vector<int> &arr, int n)
{
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < ssmallest)
        {
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

bool check_Sorted(vector<int> &arr, int n)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}
// This will take O(n) time complexity

/*
// Remove Duplicates in place from sorted array
// Bruteforce method
int removeDuplicates(vector<int> &arr, int n)
{
    set<int> s;

    // Insert all elements into the set to remove duplicates
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    int index = 0;
    //This takes O(n log(n)) time complexity

    // Copy the unique elements back into the array
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        arr[index] = *it;
        index++;
    }
    //This takes O(n) time complexity

    // Resize the array to only keep unique elements
    arr.resize(index);

    // Return the new size of the array
    return index;

    // so Total time complexity is O(n*log(n) + n)
    // whereas space complecity is O(n)
}
*/

// Another method which is optimal method
int duplicate(vector<int> &arr, int n)
{
    if (n == 0)
        return 0;

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[++i] = arr[j];
        }
    }
    return i + 1;
}
// The time complexity for this method is O(n)
// Whereas the space complexity is O(1)

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

    // Largest and second largest
    int result_1 = largest(arr, n);
    cout << "The largest element is: " << result_1 << endl;

    if (n > 1)
    {
        int result_2 = second_largest(arr, n);
        if (result_2 == INT_MIN)
        {
            cout << "There is no second largest element (array elements may be equal)." << endl;
        }
        else
        {
            cout << "The second largest element is: " << result_2 << endl;
        }
    }
    else
    {
        cout << "Array is too small to find a second largest element." << endl;
    }

    // second smallest
    if (n > 1)
    {
        int result_3 = second_smallest(arr, n);
        if (result_3 == INT_MAX)
        {
            cout << "There is no second smallest element (array elements may be equal)." << endl;
        }
        else
        {
            cout << "The second smallest element is: " << result_3 << endl;
        }
    }
    else
    {
        cout << "Array is too small to find a second smallest element." << endl;
    }

    // to check array is sorted or not
    bool sorted = check_Sorted(arr, n);
    if (sorted)
        cout << "The array is sorted." << endl;
    else
        cout << "The array is not sorted." << endl;

    // To remove duplicate elements
    //  int newSize = removeDuplicates(arr, n);

    sort(arr.begin(), arr.end()); // use this when duplicate function is used,
    // Otherwise don't use it on calling bruteforce method
    int newSize = duplicate(arr, n);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}