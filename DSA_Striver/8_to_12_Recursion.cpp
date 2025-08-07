#include <bits/stdc++.h>
using namespace std;

// void print()
// {
//     cout << 1 << endl;
//     print();
// }

void Name(int i, int n)
{
    if (i > n)
    {
        return;
    }
    else
    {
        cout << "Ram" << " ";
        Name(i + 1, n);
    }
}

int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return n + sum(n - 1);
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

void Reverse(int i, int arr[], int n)
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    Reverse(i + 1, arr, n);
}

// Recursive function to check if a string is a palindrome
bool isPalindrome(string &str, int start, int end)
{
    // Base case: if the string has only one character or is empty
    if (start >= end)
    {
        return true;
    }
    // Check if the characters at the current indices are equal
    if (str[start] != str[end])
    {
        return false;
    }
    // Recursive case: move towards the center of the string
    return isPalindrome(str, start + 1, end - 1);
}

bool Palindrome(int i, string &s)
{
    if (i >= s.size() / 2)
        return true;
    if (s[i] != s[s.size() - i - 1])
        return false;
    return Palindrome(i + 1, s);
}

int Fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main()
{
    // print();
    // Name(1, 5);
    // cout << endl;
    // cout << sum(10) << endl;
    // cout << factorial(5) << endl;

    // int n;
    // cout << "Enter the size of array: ";
    // cin >> n;
    // int arr[n];
    // cout << "Enter the elements of the array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // Reverse(0, arr, n);

    // cout << "Reversed array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // string input;
    // cout << "Enter a string: ";
    // cin >> input;

    // if (isPalindrome(input, 0, input.length() - 1))
    // {
    //     cout << "The string is a palindrome." << endl;
    // }
    // else
    // {
    //     cout << "The string is not a palindrome." << endl;
    // }

    string s = "MADAM";
    cout << Palindrome(0, s) << endl;
    cout << Fibonacci(4);

    return 0;
}
