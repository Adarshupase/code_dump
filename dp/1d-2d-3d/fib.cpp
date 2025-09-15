#include <bits/stdc++.h>

using namespace std;

//recursion
int fib(int n,vector<int>& dp)
{
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1,dp) + fib(n-2,dp);



}

//O(n) 
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> dp(n,-1);
//     cout << fib(n,dp) << "\n";
//     return 0;

// }
//Tabulation 
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> dp(n+1,-1);

//     dp[0] = 0;dp[1] = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i-1] + dp[i-2];
//     }
//     return dp[n];
// }

//O(1) space

int main()
{
    int n;
    cin >> n; 
    int prev = 1,prev2 = 0;

    for(int i = 2; i <= n ; i++)
    {
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
        
    }
    cout << prev << "\n";

}