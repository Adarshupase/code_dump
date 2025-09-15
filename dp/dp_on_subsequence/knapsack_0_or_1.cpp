#include <bits/stdc++.h>

using namespace std;

int f(int ind,int W,vector<int>& wt, vector<int>& val)
{
    if(ind == 0) {
        if(wt[0] <= W) return val[0];
        return 0;
    }

    int notTake = f(ind - 1,W,wt,val);

    int take = INT_MIN;

    if(wt[ind] <= W) take = val[ind] + f(ind-1,W-wt[ind],wt,val);

    return max(take,notTake);

}

int knapsack(int W,vector<int>& val,vector<int>& wt)
{
    int n = wt.size();
    return f(n-1,W,wt,val);

}

int knapsack2(int maxWeight,vector<int>& val,int n, vector<int>& wt)
{
    vector<vector<int>> dp(n,vector<int>(maxWeight + 1,0));

    for(int W = wt[0]; W <= maxWeight; W++)
    {
        dp[0][W] = val[0];
    }

    for (int ind = 1; ind < n ;ind++){
        for(int W = 0 ; W <= maxWeight; W++){
            int notTake = 0 + dp[ind-1][W];
            int take = INT_MIN;
            if(wt[ind] <= W){
                take = val[ind] + dp[ind-1][W-wt[ind]];
            }
            dp[ind][W] = max(take,notTake);
        }
    }
    return dp[n-1][maxWeight] ;
}
