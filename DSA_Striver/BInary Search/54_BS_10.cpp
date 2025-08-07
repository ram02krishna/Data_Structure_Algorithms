// Finding Sqrt of a number using Binary Search
// Problem Statement : You are given a positive integer n.Your task is to find and return its square root.If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.
// Note : The question explicitly states that if the given number,n, is not a perfect square, our objective is to find the maximum number, x, such that x squared is less than or equal to n(x *x <= n).In other words, we need to determine the floor value of the square root of n.

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
int floorSqrt(int n)
{
    int ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        long long val = i * i;
        if (val <= n)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}
// Time complexity : O(n)
// Space complexity : O(1)

// Optimal Approach - 1 :(Using inbuilt function)
int floor_Sqrt(int n)
{
    int ans = sqrt(n);
    return ans;
}
// Time Complexity: O(logN), N = size of the given array.
// Reason: We are basically using the Binary Search algorithm.

// Space Complexity : O(1) as we are not using extra space

// Optimal Approach - 2:(Using Binary Search)
int Floor_Sqrt(int n)
{
    int low = 0, high = n;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n))
        {
            // Eliminate the left half:
            low = mid + 1;
        }
        else
        {
            // Eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}
// Time complexity  : O(log(n) (to the base 2))
// Space Complexity : O(1)
int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n << " is: " << ans << endl;

    int ans1 = floor_Sqrt(n);
    cout << "The floor of square root of(By optimal approach - 1) " << n << " is : " << ans1 << endl;

    int ans2 = Floor_Sqrt(n);
    cout << "The floor of square root of(By optimal Approach - 2) " << n << " is : " << ans2 << endl;

    return 0;
}
