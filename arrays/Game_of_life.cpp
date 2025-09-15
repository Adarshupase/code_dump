#include <bits/stdc++.h>

using namespace std;

int kadane(vector<int>& nums, int k)
{
    int currSum = 0;
    int ans = INT_MIN;

    for(int num : nums){
        currSum = max(currSum,nums[i]);
        ans = max(ans,currSum);
        
    }
    return ans;
    
}


