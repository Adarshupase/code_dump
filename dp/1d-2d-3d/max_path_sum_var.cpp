#include <bits/stdc++.h>

using namespace std;
int f(int i,int j,vector<vector<int>>& grid,int m,int n,vector<vector<int>>& dp)
{
    if(j < 0 || j >= m) return -1e9;

    if(i == 0) return grid[i][j];

    if(dp[i][j] != -1) return dp[i][j];
    int topL = grid[i][j] + f(i-1,j-1,grid,n,m,dp);
    int topR = grid[i][j] + f(i - 1, j + 1, grid,n,m,dp);
    int top = grid[i][j] + f(i - 1, j , grid,n,m,dp);
    return dp[i][j] = max(topL,max(topR,top));
    
}
int getmaxPathSum(int n,int m,vector<vector<int>>& grid)
{
    int maxi = 0;
    vector<vector<int>> dp(n,vector<int>(m,-1));

    for(int i = 0 ; i < m ; i++){
        maxi = max(maxi,f(0,i,grid,n,m,dp));
    }
    return maxi;
}


int getMaxPathSum2(int n, int m, vector<vector<int>>& grid)
{
    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int j = 0 ; j < m ; j++){
        dp[0][j] = grid[0][j];
    }

    for(int i = 1; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int top = grid[i][j] + dp[i-1][j];
            int topL = grid[i][j];
            if ( j-1 >= 0) topL += dp[i-1][j-1];
            else topL -= 1e9;
            int topR = grid[i][j];
            if (j + 1< m)  topR += dp[i-1][j+1];
            else topR -= 1e9;
            dp[i][j] = min({top,topL,topR});
        }
    }
    return dp[m-1][n-1];
}
int getMaxPathSum3(int n,int m,vector<vector<int>>& grid)
{
    vector<int> prev(m,0);
    for(int i = 0 ; i < m ; i++){
        prev[i] = grid[0][i];
    }
    for(int i = 1; i < n ; i++){
        vector<int> cur(m,0);

        for(int j = 0; j < m ; j++){
            int top = grid[i][j] + prev[j];
            int topL = grid[i][j];
            if ( j-1 >= 0) topL += prev[j-1];
            else topL -= 1e9;
            int topR = grid[i][j];
            if (j + 1< m)  topR += prev[j+1];
            else topR -= 1e9;
            cur[j] = min({top,topL,topR});
        }
        prev = cur;
    }
    return prev[m-1];
}