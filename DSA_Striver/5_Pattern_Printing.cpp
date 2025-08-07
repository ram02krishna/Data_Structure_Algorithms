// Pattern Printing

#include <bits/stdc++.h>
using namespace std;

void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " *";
        }
        cout << endl;
    }
}
void print2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " *";
        }
        cout << endl;
    }
}
void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " " << j;
        }
        cout << endl;
    }
}
void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " " << i;
        }
        cout << endl;
    }
}
void print5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            cout << " *";
        }
        cout << endl;
    }
}
void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << " " << j;
        }
        cout << endl;
    }
}
void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        // for space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // for star
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        // for space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print8(int n)
{
    for (int i = 0; i < n; i++)
    {
        // for space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // for stars
        for (int j = 0; j < (2 * n - (2 * i + 1)); j++)
        {
            cout << "*";
        }
        // for space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print9(int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print10(int n)
{
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 1; i <= n - ((n + 1) / 2); i++)
    {
        for (int j = i; j <= n - ((n + 1) / 2); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print11(int n)
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}
void print12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}
void print13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num = num + 1;
        }
        cout << endl;
    }
}
void print14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void print15(int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void print16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void print17(int n)
{
    for (int i = 0; i < n; i++)
    {
        // for spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // for characters
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }
        // for spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void print18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void print19(int n)
{
    int inis = 0;
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 0; j < inis; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        inis += 2;
        cout << endl;
    }
    inis = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {
        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 0; j < inis; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        inis -= 2;
        cout << endl;
    }
}
void print20(int n)
{
    int inis = 8;
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 1; j <= i + 1; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 0; j < inis; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= i + 1; j++)
        {
            cout << "*";
        }
        inis -= 2;
        cout << endl;
    }
    inis = 2;
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 1; j < n - i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 0; j < inis; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j < n - i; j++)
        {
            cout << "*";
        }
        inis += 2;
        cout << endl;
    }
}
void print21(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    print9(n);
    // print21(n);
    return 0;
}