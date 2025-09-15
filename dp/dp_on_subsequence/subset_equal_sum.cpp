#include <bits/stdc++.h>

using namespace std;


bool f(int ind,int target,vector<int>& nums,vector<vector<int>>& dp)
{
    if(target == 0) return true;
    if(ind == 0) return nums[0] == target;
    if(dp[ind][target] != -1) return dp[ind][target];
    bool notTake = f(ind-1,target,nums,dp);
    bool take = false;
    
    if(target >= nums[ind]) {
        take = f(ind - 1,target - nums[ind], nums,dp);
    }

    return dp[ind][target] = take || notTake;
}

bool subsetSumK(int n, int k, vector<int>& nums)
{
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    //just return dp[n-1][]
    return f(n-1, k,  nums, dp);
}
bool isSubsetSumKTabulation(int n, int k, vector<int>& nums)
{
    vector<bool> prev(k+1,0), cur(k+1,0);
    prev[0] = cur[0] = true;
    prev[nums[0]] = true;

    for(int ind = 1; ind <n ; ind++){
        
        for(int target = 1; target <= k; target++){
            bool notTake = prev[target];
            bool take = false;
            
            if(target >= nums[ind]) {
                take = cur[target-nums[ind]];
            }

            cur[target] = take || notTake;            
        }
    }
    return prev[k];


}
int main()
{
    int n,k ;
    cin >> n;
    cin >> k;
    vector<int> nums(n);
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }
    cout << "ANS" << "\n";
    cout << subsetSumK(n,k,nums);
}