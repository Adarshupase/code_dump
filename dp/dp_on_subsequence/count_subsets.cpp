#include <bits/stdc++.h>

using namespace std;
int f(int ind, int target, vector<int>& nums,vector<vector<int>>& dp)
{

    if(target == 0) return 1;
    if(ind == 0) {
        if(target == 0 && nums[0] == 0) return 2;
        if (target == 0 || nums[0] == target) return 1;
    }
    if(dp[ind][target] != -1){
        return dp[ind][target];
    }

    int notTake = f(ind-1,target,nums,dp);
    int take = 0;
    if (target >= nums[ind])  {
        take = f(ind-1,target-nums[ind], nums,dp);
    }
    return dp[ind][target] = take + notTake;
}
int countSubsetsithSumK(int n, int k,vector<int>& nums)
{
    vector<vector<int>> dp(n,vector<int>(k+1,-1));

    return f(n-1,k,nums,dp);
}