#include <bits/stdc++.h>

using namespace std;

int f(int i ,int j, vector<vector<int>>& grid)
{
    if ( i== 0 && j == 0) return grid[i][j];

    if(i < 0 && j < 0) return INT_MAX;

    int left = grid[i][j] + f(i,j-1,grid);
    int up = grid[i][j] + f(i-1,j,grid);

    return min(left,up);
}

int minPathSum(vector<vector<int>>& grid)
{

    int n = grid.size(), m = grid[0].size();
    return f(n-1,m-1,grid);
}

int minPathSum2(vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>>dp(n, vector<int>(m,INT_MAX));
    dp[0][0]  = grid[0][0];
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]) + grid[i][j];
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1]) + grid[i][j];

        }

    }
    return dp[n-1][m-1];
}