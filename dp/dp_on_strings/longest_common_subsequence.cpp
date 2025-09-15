#include <bits/stdc++.h>

using namespace std;
/**
 * longest common subsequence
 * can be or cannot be consecutive 
 * but need to be in order
 * s1 = adebc s2 = dcadb ans = adb 
 * ans = 4
 */
int f(int i, int j, string& s, string& t,vector<vector<int>>& dp)
{
    if(i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if(s[i] = t[j]){
        return 1 + f(i-1,j-1,s,t,dp);
    }
    else {
        return max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    }
}
int longestCommonSubsequence(string s,string t)
{
    
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,s,t,dp);
}

int lcs(string s,string t)
{
    int n = s.size(), m = s.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = 0;
    }
    for(int j = 0 ; j <= m ; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= n  ; i++){
        for(int j = 1; j <= m ; j++){
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }

    }                                                              
    return dp[n][m];
}
    //acd and ced cd -> cd
    //some recurrence through the way 
    // rules to write recurrence 
    //f(2) -> string till index2 (ind1,ind2) ind1 for s1 
    //ind2 for s2 
    //f(2,2) lcs of s1[0..2]  and s2[0..2]
    //explore all possibilities
    //acd and ced
    //do comparison character wise d and d 
    // 1 + ac | ce 
    // 1 + f(1,1)  
    // match and not match ac and ce 
    // move ind1 keep ind2 and mov ind2 and keep ind1
    //ac and ce  => max(f(ind1-1,ind2),f(ind1,ind2-1))

    /**
     * f(ind1,ind2) 
     *      if (s1[ind1] == s1[ind2])
     *          return 1 + f(ind1-1,ind2-1)
     *  return 0 + max(f(ind1-1,ind2),f(ind1,ind2-1))
     * 
     * base case 
     * negative ind means end of the string if (ind1 < 0 || ind2 < 0) return 0;
     * 
     * 
     */