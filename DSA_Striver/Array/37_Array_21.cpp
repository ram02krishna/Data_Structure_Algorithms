// 4 Sum -> We have an array nums in which nums[i] + nums[j] + nums[k] + nums[l] == target where i!=j!=k!=l

#include <bits/stdc++.h>
using namespace std;

// Brut Force Method
vector<vector<int>> foursum(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// Time complexity -> O(n^4)
// Space complexity -> O(no. of quads)*2

// Better Solution
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                // taking bigger data type
                // to avoid integer overflow:
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


int main()
{
    vector<int> nums = {-1, 0, 2, 6, 9, -6, -5, 3, 0, -7, -2};
    cout << "The Four sum result is :: " << endl;
    vector<vector<int>> result = foursum(nums, 0);
    for (auto it : result)
    {
        cout << "[" << it[0] << ", " << it[1] << ", " << it[2] << ", " << it[3] << "]" << endl;
    }
    cout << endl;
    cout<<endl;
    vector<vector<int>> result1 = fourSum(nums, 0);
    for (auto it : result1)
    {
        cout << "[" << it[0] << ", " << it[1] << ", " << it[2] << ", " << it[3] << "]" << endl;
    }
    cout << endl;

    return 0;
}