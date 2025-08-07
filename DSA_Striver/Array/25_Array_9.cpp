// Rearrange Array Elements by sign

#include <bits/stdc++.h>
using namespace std;

// Brute Force Method:
int maxProfit(vector<int> &price)
{
    int maxPro = 0;
    int n = price.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (price[j] > price[i])
            {
                maxPro = max(price[j] - price[i], maxPro);
            }
        }
    }
    return maxPro;
}
// Time complexity: O(n^2)
// Space Complexity: O(1)

// Optimal Method:
int BestTime(vector<int> &price, int n)
{
    int mini = price[0];
    int max_Profit = 0;
    for (int i = 1; i < n; i++) // Start from 1 as price[0] is already considered
    {
        int cost = price[i] - mini;
        max_Profit = max(max_Profit, cost);
        mini = min(mini, price[i]);
    }
    return max_Profit;
}

int main()
{
    int n;
    cout << "Enter the size of the array price: ";
    cin >> n;
    cout << endl;

    vector<int> price(n);
    cout << "Enter the elements of the array price: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    int res = maxProfit(price);
    cout << "The maximum profit (Brute Force): " << res << endl;

    int res1 = BestTime(price, n);
    cout << "The maximum profit (Optimal): " << res1 << endl;

    return 0;
}
