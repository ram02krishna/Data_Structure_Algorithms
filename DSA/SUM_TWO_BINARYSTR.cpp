#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.length() - 1;
        int j = b.length() - 1;
        string c;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry != 0)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }
            c.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(c.begin(), c.end());
        return c;
    }
};

// Example usage
int main()
{
    Solution solution;
    string a = "1010";
    string b = "1011";
    string sum = solution.addBinary(a, b);
    printf("Sum: %s\n", sum.c_str()); // Output: "10101"
    return 0;
}