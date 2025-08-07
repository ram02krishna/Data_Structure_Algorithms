/*
#include <bits/stdc++.h>
using namespace std;
// Selection sorting

// void selection_sort(int arr[], int n)
// {
//     for (int i = 0; i <= n - 2; i++)
//     {
//         int min = i;
//         for (int j = i; j < n; j++)
//         {
//             if(arr[j]<arr[min])
//             {
//                 min = j;
//             }
//         }
//         int temp = arr[min];
//         arr[min] = arr[i];
//         arr[i] = temp;
//     }
// }
// Time complexity is O(n^2)

// void bubble_sort(int arr[], int n)
// {
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j + 1];
//                 arr[j + 1] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

// OR

// void bubble_sort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - 1 - i; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 swap(arr[i], arr[j]);
//             }
//         }
//     }
// }


// Time complexity in worst and average case is O(n^2) whereas best time complexity is O(n)

// Insertion sort
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) { // Start from the second element
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) { // Ensure j-1 is valid
            int temp = arr[j - 1]; // Swap elements
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

// Time complexity of Insertion Sort is O(n^2) in the worst case

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        }

        // selection_sort(arr, n);
        // bubble_sort(arr, n);
    insertion_sort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

// void recursive_bubble_sort(vector<int> &arr, int n)
// {
//     if (n == 1) // Base case: If array size is 1, it's already sorted
//         return;

//     for (int j = 0; j <= n - 2; j++)
//     {
//         if (arr[j] > arr[j + 1])
//         {
//             // Swap arr[j] and arr[j+1]
//             int temp = arr[j + 1];
//             arr[j + 1] = arr[j];
//             arr[j] = temp;
//         }
//     }

//     // Call the function recursively for the remaining part
//     recursive_bubble_sort(arr, n - 1);
// }

void insertionSortRecursive(vector<int> &arr, int n)
{ // Pass arr by reference
    // Base case: if array has one or zero elements, it's already sorted
    if (n <= 1)
        return;

    // Sort the first n-1 elements recursively
    insertionSortRecursive(arr, n - 1);

    // Insert the nth element at its correct position
    int last = arr[n - 1];
    int j = n - 2;

    // Move elements of arr[0..n-1], that are greater than 'last',
    // to one position ahead of their current position
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    // Place 'last' in its correct position
    arr[j + 1] = last;
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

    // recursive_bubble_sort(arr, n);
    insertionSortRecursive(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}