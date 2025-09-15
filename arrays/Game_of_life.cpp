#include <bits/stdc++.h>

using namespace std;

int kadane(vector<int>& nums, int k)
{
    int currSum = 0;
    int ans = INT_MIN;

    for(int i = 0 ; i < nums.size(); i++){
        currSum += nums[i];
        
        ans = max(currSum,ans);

        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return ans;
}

