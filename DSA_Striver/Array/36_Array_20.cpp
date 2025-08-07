// 3 Sum -> You have given an array in which you have to find triplets whose sum must be equal to 0 in which you can not take same element more than one time.only unique triplet must be there means you have to consider one of the triplets from [-1,2,-1],[-1,-1,2],[2,-1,-1]
#include <bits/stdc++.h>
using namespace std;
// Brut Force solution
vector<vector<int>> triplet(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// Time complexity -> O(n^3)
// Space complexity -> O

// Better Solution
// By using Hashing bcz of lagarithmic or constant time
vector<vector<int>> Triplet(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// Time complexity -> O((n^2)*(log m))
// Space complexity -> O(n) + O(No.of Unique triplets) * 2

// Optimal Solution
//  Algorithm will be two pointer approach
//  Sort the array first
vector<vector<int>> Threesum_Triplet(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {

            int sum = (nums[i] + nums[j] + nums[k]);
            if (sum < 0)
            {
                j++;
            }   
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && nums[i] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
        return ans;
    }
}
// Time complexity = O(n*log(n)) -> to sort the array + O(n * n) -> for loop and while loop
// Space complexity = O(No. Of Unique Elements)

int main()
{
    vector<int> nums = {1, -1, 2, 3, -3, 0, -6, 0, 6};
    cout << "The Triplets are :: " << endl;
    vector<vector<int>> three_sum = triplet(nums);
    for (const auto &triplet : three_sum)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    cout << endl;

    cout << "The Triplets are :: " << endl;
    vector<vector<int>> threesum = Triplet(nums);
    for (const auto &Triplet : threesum)
    {
        cout << "[" << Triplet[0] << ", " << Triplet[1] << ", " << Triplet[2] << "]" << endl;
    }

    cout << "The Triplets are :: " << endl;
    vector<vector<int>> Threesum_Result = Threesum_Triplet(nums);
    for (const auto &threesum : Threesum_Result)
    {
        cout << "[" << threesum[0] << ", " << threesum[1] << ", " << threesum[2] << "]" << endl;
    }
    return 0;
}
