#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
    int n = nums.size();
    int k = 0; 
    for (int j = 1; j < n ; j ++) {
        if(nums[k] != nums[j]){
            j++;
            swap(nums[k],nums[j]);
        }

    }
    return k + 1;
}