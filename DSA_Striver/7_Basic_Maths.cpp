// Given a number n. Count the number of digits in n which evenly divide n. Return an integer, total number of digits of n which divides n evenly.

// Note :- Evenly divides means whether n is divisible by a digit i.e. leaves a remainder 0 when divided.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Count_Digits(int N)
    {
        int count = 0;
        int originalNumber = N;

        // Traverse through each digit of the number
        while (N > 0)
        {
            int digit = N % 10;
            if (digit != 0 && originalNumber % digit == 0)
            {
                count++;
            }
            N /= 10;
        }
        cout << "The value of count is " << count << endl;
        return count;
    }

    // Function to reverse the given number
    int Reverse_Number(int n)
    {
        int reverse = 0;
        // Traverse through each digit of the number
        while (n > 0)
        {
            int k = n % 10;
            reverse = reverse * 10 + k;
            n = n / 10;
        }
        cout << "Reverse of the number is " << reverse << endl;
        return reverse;
    }
    // Time complexity of Count_Digits is O(log(N)) -> Base 10
    // Time complexity of Reverse_Number is O(log(N)) -> Base 10

    void Palindrome(int n)
    {
        int duplicate = n;
        int reverse = 0;
        while (n > 0)
        {
            int k = n % 10;
            reverse = reverse * 10 + k;
            n = n / 10;
        }
        if (reverse == duplicate)
        {
            cout << "Yes,The number is palindrome" << endl;
        }
        else
        {
            cout << "No,The number is not palindrome" << endl;
        }
    }

    void Armstrong(int n)
    {
        int number = n;
        int new_number = 0;
        while (n > 0)
        {
            int k = n % 10;
            new_number += k * k * k;
            n = n / 10;
        }
        if (number == new_number)
        {
            cout << "Yes,integer " << number << " is an Armstrong Number" << endl;
        }
        else
        {
            cout << "No,integer " << number << " is not an Armstrong Number" << endl;
        }
    }

    void LCM_GCD(int n1, int n2)
    {
        int number_1 = n1;
        int number_2 = n2;
        int GCD = 1;
        // for (int i = 1; i <= 9; i++)
        for (int i = 1; i <= min(n1, n2); i++)
        {
            if (n1 % i == 0 && n2 % i == 0)
            {
                GCD = GCD * i;
            }
        }
        cout << "HCF or GCD of the numbers " << number_1 << " and " << number_2 << " is " << GCD << endl;
        int LCM = GCD;
        int k1 = n1 / GCD;
        LCM = GCD * k1;
        int k2 = n2 / GCD;
        LCM = LCM * k2;
        cout << "LCM  of the numbers " << number_1 << " and " << number_2 << " is " << LCM << endl;

        // Time complexity for GCD -> O(min(n1,n2))
    }

    void Print_Diviors(int n)
    {
        int num = n;
        cout << "Divisors of " << num << " are ";
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    void print_divisors(int n)
    {
        vector<int> ls;
        // 6 * 6 <= 36
        // 7 * 7 <= 36  false
        // O(sqrt(n))
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ls.push_back(i);
                if ((n / i) != i)
                {
                    ls.push_back(n / i);
                }
            }
        }
        // O(no of factors * log(no of factors)) : n is the number of factors
        sort(ls.begin(), ls.end());
        // O(number of factors)
        for (auto it : ls)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    void prime(int n)
    {
        int count = 0;
        int num = n;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                count++;
                if ((n / i) != i)
                {
                    count++;
                }
            }
        }
        if (count == 2)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }
    // EUCLIDEAN ALGORITHM
    // it's say that GCD or HCF of two numbers n1 and n2 is given by GCD(n1,n2) = GCD(n1-n2,n2) where n1 > n2
    // GCD(n1,n2) -> GCD(n1-n2,n2) -> GCD(n1-n2-n2,n2) -> ............ -> GCD(0,n2),Hence n2 is the GCD of the numbers n1 and n2
    // GCD(n1,n2) = GCD(n1%n2,n2) where n1>n2

    void GCD(int n1, int n2)
    {
        while (n1 > 0 && n2 > 0)
        {
            if (n1 > n2)
            {
                n1 = n1 % n2;
            }
            else
            {
                n2 = n2 % n1;
            }
        }
        if (n1 == 0)
        {
            cout << n2;
        }
        else
        {
            cout << n1;
        }
    }
};

int main()
{
    Solution s;
    s.Count_Digits(14586);
    s.Reverse_Number(145);
    s.Palindrome(200151002);
    s.Palindrome(20015102);
    s.Armstrong(371);
    s.Armstrong(125);
    s.LCM_GCD(14, 8);
    s.Print_Diviors(36);
    s.print_divisors(36);
    s.prime(25);
    s.prime(17);
    s.GCD(12, 3);

    return 0;
}