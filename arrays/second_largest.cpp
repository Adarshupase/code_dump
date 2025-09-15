#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>& nums) 
{
    int n = nums.size();

    int prev = -1, cur = nums[0];

    for(int i = 1; i < n ; i++) {
        if (nums[i] > cur) {
            prev = cur ; 
            cur = nums[0];
        }
        else if(nums[i] > nums[i] != cur ){
            prev =nums[i];
        }
    }
    return prev;
}