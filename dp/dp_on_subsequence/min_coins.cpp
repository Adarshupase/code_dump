#include <bits/stdc++.h>

using namespace std;

//given arr[] of denominations of coins you can choose a coin any number
//of times return the minimum number of coins that can be used to sum 
//upto target.

/**
 * {1,2,3} t = 7
 * {3,3,1} 
 * {9,6,5,1} t= 1
 * {9,1,1}
 * {6,5} is the answer
 */

 /**
  * take the combo that has minimum coins 
  */

int f(int ind,int target,vector<int>& coins)
{
    if(ind == 0) {
        if(target % coins[ind] == 0) return target/coins[ind];
    }
    else {
        return 1e9;
    }
    int notTake = 0 + f(ind-1,target,coins);
    int take = INT_MAX;
    if(coins[ind] <= target) {
        take = 1 + f(ind,target-coins[ind],coins);
    }

    return min(take,notTake);

}
int minCoins(int n, vector<int>& coins, int target)
{

    int ans = f(n-1,target,coins);
    if (ans >= 1e9) return -1;
    return ans;

}
int f2(int ind,int target,vector<int>& coins,vector<vector<int>>& dp)
{
    if(ind == 0) {
        if(target % coins[ind] == 0) return target/coins[ind];
    }
    else {
        return 1e9;
    }

    if(dp[ind][target] != -1) return dp[ind][target];
    int notTake = 0 + f2(ind-1,target,coins,dp);
    int take = INT_MAX;
    if(coins[ind] <= target) {
        take = 1 + f2(ind,target-coins[ind],coins,dp);
    }

    return dp[ind][target] = min(take,notTake);


}

int minCoins2(int n, vector<int>& coins, int target)
{
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    int ans = f2(n-1,target,coins,dp);
    if (ans >= 1e9) return -1;
    return ans;

}

int minCoins3(int n, vector<int>& coins, int target)
{
    vector<vector<int>> dp(n,vector<int>(target+1,0));

    for (int t = 0; t < target ; t++){
        if (t % coins[0] == 0) dp[0][t] = t/coins[0];
        else dp[0][t] = INT_MAX;
    }

    for(int index = 1 ; index < n; index++){
        for(int t = 0; t <= target; t++){
            int notTake = dp[index-1][t];
            int take = INT_MAX;
            if(coins[index] <= t ){
                take = 1 + dp[index][t-coins[index]];
            }
            dp[index][t] = min(take,notTake);

        }

    }
    int ans = dp[n-1][target] ;
    if (ans >= 1e9) return -1;
    return ans;


}