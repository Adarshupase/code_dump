#include <iostream>
#include <vector>
#include <algorithm>

int max_consecutive_1s(std::vector<int> &nums,int k){
    int zeros = 0,maxlen = 0;
    int l = 0;
    int n = nums.size();
    for(int right = 0; right < n ; right++){
        if(nums[right] == 0){
            zeros++;
        }
        while (zeros > k){
            if(nums[l] == 0){
                zeros--;
            }
            l++;
        }
        if(zeros <= k){
            maxlen = std::max(maxlen, right - l + 1);
        }
    }
}