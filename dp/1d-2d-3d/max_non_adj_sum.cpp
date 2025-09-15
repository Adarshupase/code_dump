#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int f(int index,vector<int>& nums,vector<int>& dp)
    {
        if(index == 0)
        {
            return nums[index];
        }
        if (index == -1)
        {
            return 0;
        }

        int pick = nums[index] + f(index-2,nums,dp);
        int notPick = f(index-1,nums,dp);
        return max(pick,notPick);
    }
    int maxNonAdjSum(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
    int maxNonAdjSum2(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n+1);
        dp[0] = nums[0];
        for (int i = 1 ; i < n; i++){
            int pick = nums[i] + (i-2)>=0?dp[i-2]:0;
            int notPick = 
            dp[i] = max(nums[i] + dp[i-2] , dp[i-1]);
        }

    }
    int maxNonAdjSum3(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        
        for(int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1) 
                take += prev2;
            int notTake = 0 + prev;

            int curi = max(take,notTake);

            prev2 = prev;
            prev = curi;
        }
    }
    
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << s.maxNonAdjSum(nums);
}
