#include <bits/stdc++.h>
using namespace std;

/*
// Left Rotate the array by one place
void leftRotate(vector<int> &arr, int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

// Time complexity -> O(n)
// Space complexity -> O(n) (array size)
// Extra space used -> O(1) (no additional space)

// Left Rotate the array by d places
void L_Rotate(vector<int> &arr, int d, int n)
{
    d = d % n;
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }
}
// Time complexity = O(n) + O(n-d) + O(d)
// Space complexity for extra space = O(d)

// Another method
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    if (k == 0)
    {
        return;
    }
    reverse(nums.begin(), nums.end());       // This will take time complexity O(d)
    reverse(nums.begin(), nums.begin() + k); // This will take time complexity O(n-d)
    reverse(nums.begin() + k, nums.end());   // This will take time complexity O(n)
}
*/

/*
// Move all the zeroes to the end of the array
vector<int> move_zeros(int n, vector<int> arr)
{
    int j = 0; // Index to place the next non-zero element
    // Loop through the array and move all non-zero elements forward
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    // At the end, all non-zero elements are at the front, and zeros are at the back
    return arr; // Return the modified array
}
*/

/*
// Linear Search
int linear_Search(vector<int> &arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
*/

// Union of two sorted array
vector<int> sortedArray(vector<int> &arr, vector<int> &arr1, int n, int m)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        st.insert(arr1[i]);
    }
    vector<int> temp;
    for (auto it : st)
    {
        temp.push_back(it);
    }
    return temp;
}

// Another Method
vector<int> sortedarray(vector<int> &arr, vector<int> &arr1, int n, int m)
{
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    // Traverse both arrays simultaneously
    while (i < n && j < m)
    {
        if (arr[i] < arr1[j])
        {
            // Avoid duplicates
            if (unionArr.empty() || unionArr.back() != arr[i])
                unionArr.push_back(arr[i]);
            i++;
        }
        else if (arr[i] > arr1[j])
        {
            // Avoid duplicates
            if (unionArr.empty() || unionArr.back() != arr1[j])
                unionArr.push_back(arr1[j]);
            j++;
        }
        else
        {
            // If both elements are equal, insert only one of them
            if (unionArr.empty() || unionArr.back() != arr[i])
                unionArr.push_back(arr[i]);
            i++;
            j++;
        }
    }
    // Add remaining elements from arr
    while (i < n)
    {
        if (unionArr.empty() || unionArr.back() != arr[i])
            unionArr.push_back(arr[i]);
        i++;
    }
    // Add remaining elements from arr1
    while (j < m)
    {
        if (unionArr.empty() || unionArr.back() != arr1[j])
            unionArr.push_back(arr1[j]);
        j++;
    }
    return unionArr;
}
// Time complexity -> O(n+m)
// Space complexity -> O(n+m) [WORST CASE]

// Intersection of sorted arrays
vector<int> ArrayIntersection(vector<int> &arr, vector<int> &arr1, int n, int m)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    // Sort both arrays
    sort(arr.begin(), arr.end());
    sort(arr1.begin(), arr1.end());
    while (i < n && j < m)
    {
        if (arr[i] < arr1[j])
        {
            i++;
        }
        else if (arr1[j] < arr[i])
        {
            j++;
        }
        else
        {
            ans.push_back(arr[i]);
            i++;
            j++;
        }
    }
    return ans;
}
// Time complexity -> O(n+m)
//  Space complexity -> O(1)

int main()
{
    int n;
    cout << "Enter the size(n) of the array: ";
    cin >> n;

    vector<int> arr(n); // Use vector to declare the array
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    /*
    // leftRotate(arr, n); // Call the rotation function
    // L_Rotate(arr, 3, n);
    rotate(arr, 3);
    // Output the array after rotation
    cout << "Array after left rotation: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
        cout << endl;

    // Move zeros to the end and update the original array
    arr = move_zeros(n, arr);
    cout << "Array after moving zeroes to the end : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    */

    /*
   int target;
   cout << "Enter the number to search: ";
   cin >> target;

   int result = linear_Search(arr, n, target);

   if (result != -1)
   {
       cout << "Element found at index " << result << endl;
   }
   else
   {
       cout << "Element not found" << endl;
   }
   */

    int m;
    cout << "Enter the size(m) of the array : " << endl;
    cin >> m;
    vector<int> arr1(m);
    cout << "Enter the elements of the array having size m : " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    cout << endl;

    vector<int> result = sortedArray(arr, arr1, n, m);
    cout << "The Union of the array arr and array arr1 is : " << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> Result = sortedarray(arr, arr1, n, m);
    cout << "The Union of the array arr and array arr1 is : " << endl;
    for (int i = 0; i < Result.size(); i++)
    {
        cout << Result[i] << " ";
    }
    cout << endl;

    vector<int> res = ArrayIntersection(arr, arr1, arr.size(), arr1.size());
    cout << "Intersection of arrays: ";
    for (int num : res)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
