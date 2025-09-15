#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int>& nums, int target) 
{
    auto ans = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    return ans;
}