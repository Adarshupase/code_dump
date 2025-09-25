#include <bits/stdc++.h>

using namespace std;

/* 
Problem Statement: Frog Jump

A frog is trying to cross a river by jumping on stones arranged in a line.
The frog starts at stone 0 (index 0) and wants to reach the last stone at index n-1.

You are given an array heights[] of size n, where heights[i] represents the height of the i-th stone.

At each step, the frog can jump either:

From stone i to stone i+1

From stone i to stone i+2 (if possible)

The cost of a jump from stone i to stone j is:

abs(heights[i] - heights[j])


Your task is to find the minimum total cost for the frog to reach stone n-1.
*/ 

int f(int ind, vector<int>& heights,vector<int>& dp)
{
    if (ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    
    int left = f(ind-1,heights,dp) + abs(heights[ind] - heights[ind-1]);

    int right = INT_MAX;

    if (ind > 1) right  = f(ind-2,heights,dp) + abs(heights[ind] - heights[ind-2]);

    return dp[ind] = min(left,right);
}
//memoization 
int frogJump(int n, vector<int>& heights,vector<int>& dp) 
{
    return f(n-1,heights,dp);
}

//tabulation 
int frogJump2(int n,vector<int>& heights)
{
    vector<int> dp(n,0);
    dp[0] = 0;
    for (int i = 1 ; i < n ; i++) {
        int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1) ss = dp[i-2] + abs(heights[i] - heights[i-2]);

        dp[i] = min(fs,ss);
    }
    return dp[n-1];
}
// 0(n) time O(1) space 
int frogJump3(int n,vector<int>& heights)
{
    int prev = 0,prev2 =0;
    for (int i = 1; i < n; i++) {
        int fs = prev + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1) ss = prev2 + abs(heights[i] - heights[i-2]);

        int curi = min(fs,ss);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main(){
    int n;
    cin >> n;
    int i = 0;
    vector<int> heights(n);
    vector<int> dp(n+1,-1);
    for (int i = 0 ; i < n ;i++)
    {
        cin >> heights[i];
    }

    // cout << frogJump(n,heights,dp) << "\n";






}
