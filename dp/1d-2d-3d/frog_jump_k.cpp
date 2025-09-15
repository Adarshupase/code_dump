#include <bits/stdc++.h>

using namespace std;

class Solution 
{
    public:
    int f(int index,vector<int>& heights,vector<int>& dp,int k)
    {
        if(index == 0) return 0;
        if(dp[index] != -1) return dp[index];
        int minSteps = INT_MAX;
        for (int j = 1; j <= k ; j++)
        {
            if (index - j >= 0){
                int jump = f(index - j, heights,dp,k) 
                            + abs(heights[index] - heights[index-j]);
                minSteps = min(minSteps,jump);
            }
            
        }
        return dp[index] = minSteps;


    }
    int frogJumpK(int n,vector<int>& heights,int k)
    {
        vector<int> dp(n,-1);
        return f(n-1,heights,dp,k);
    }
    int frogJumpKOptimized(int n,vector<int>& heights,int k)
    {
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;

        for (int i = 1 ; i < n ;i++)
        {
            for (int j = 1; j <= k ; j++)
            {
                if (i - j >= 0)
                {
                    int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                    dp[i] = min(dp[i],jump);
                }
            }
        }
        return dp[n-1];
    }
};
