#include <bits/stdc++.h>

using namespace std;

int f(int i, int j, string& s, string& t)
{   
    if(i < 0 || j < 0){
        return 0;
    }

    if (s[i] == t[j])
    {
        return 1 + f(i-1,j-1,s,t);
    }
    else{
        return 0;
    }


}
int lcs(string s,string t)
{
    int n = s.size(),m = t.size();
    return f(n-1,m-1,s,t);
}
int lcs2(string s, string t)
{
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans = 0;
    for(int i = 1 ; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return dp[n][m];
}