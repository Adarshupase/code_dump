//dp on grids
/**
 * dp on grids
 * (0,0) to (n-1,m-1)
 * fixed starting point
 * 
 */

#include <bits/stdc++.h>

using namespace std;


int f(int i, int j, int n, vector<vector<int>>& triangle)
{
    if(i == n-1) return triangle[n-1][j];
    int down = triangle[i][j] + f(i+1,j,n,triangle);
    int diag = triangle[i][j]  + f(i + 1, j+1, n,triangle);

    return min(down,diag);

}
int minPathSumTriangle(int n,vector<vector<int>>& triangle)
{
    return f(0,0,n,triangle);
}

int minPathSum2(int n,vector<vector<int>>& triangle)
{
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i = 0 ; i < n ; i++){
        dp[n-1][i] = triangle[n-1][i];
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = n-2; j >= 0; j--){
            dp[i][j] = min(dp[i][j],triangle[i][j]+ dp[i+1][j]);
            dp[i][j] = min(dp[i][j], triangle[i][j] + dp[i+1][j+1]);
        }
    }

}
int minPathSum3(int n, vector<vector<int>>& triangle)
{
    vector<int> front(n,0);

    for(int i = 0 ; i < n ; i++){
        front[i] = triangle[n-1][i];
    }


    for(int i = n-2; i >= 0; i--){
        vector<int> cur(n,0);
        for(int j = n-2; j >= 0; j--){
            cur[j] = min(cur[j],triangle[i][j]+ front[j]);
            cur[j] = min(cur[j], triangle[i][j] + front[j+1]);

        }
        front = cur;
    }
    return front[0];
}