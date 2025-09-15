#include <bits/stdc++.h>

using namespace std;


int f(int ind, vector<int>& prices,int length,vector<vector<int>>& dp)
{   
    if(ind == 0){
        return prices[0]*length;
    }
    if(dp[ind][length] != -1) return dp[ind][length];
    int notTake = 0 + f(ind - 1, prices, length,dp);
    int take = INT_MIN;
    int rod_length = ind + 1;
    if(rod_length <= length){
        take = prices[ind] + f(ind,prices,length-rod_length,dp);
    }
    return dp[ind][length]  = max(take,notTake);

}
int rodCutting(vector<int>& prices, int length)
{
    vector<vector<int>> dp(length,vector<int>(length+1,-1));
    return f(length,prices,length,dp);
}

int rodCutting2(vector<int>& prices,int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,0));

    for(int N = 0 ; N <=n ; N++){
        dp[0][N] = N * prices[0];
    }

    for(int ind = 1; ind < n ; ind++){
        for(int N = 0 ; N <= n ; N++){
            int notTake = 0 + dp[ind-1][N];
            int take = INT_MIN;
            int rod_length = ind + 1;
            if(rod_length <= N){
                take = prices[ind] + dp[ind][N-rod_length];
            }
            dp[ind][N]  = max(take,notTake);
        }
    }
}