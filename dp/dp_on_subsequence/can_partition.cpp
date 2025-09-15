#include <bits/stdc++.h>

using namespace std;
class Solution
{
    
    public:
    bool canPartition(int n,vector<int>& nums)
    {
        int total = accumulate(nums.begin(),nums.end(),0);
        if (total % 2 != 0) return false;

        int half = total / 2;
        return subSetSumK(n,half,nums);

    }
    bool subSetSumK(int n,int k, vector<int>& nums)
    { 
        vector<bool> prev(k+1,0),cur(k+1,0);

        prev[0] = true;

        if(nums[0] <= k) prev[nums[0]] = true;

        for(int index = 1; index < n; index++){
            cur[0] = true;
            for(int target = 1; target <= k; target++){
                bool notTake = prev[target];

                bool take = false;

                if(nums[index] <= target){
                    take = prev[target-nums[index]];
                }
                cur[target] = take || notTake;
            }
            prev = cur;
        }
        return prev[k];
    }
    
};

int main()
{
    Solution s;
    int n; 
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n ; i++){
        cin >> nums[i];
    }
    cout << s.canPartition(n,nums) << "\n";

}
