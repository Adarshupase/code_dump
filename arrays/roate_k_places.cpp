#include <bits/stdc++.h>

using namespace std;


vector<int> rotateLeft(vector<int>& nums, int k)
{
    reverse(nums.begin() , nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(),nums.end());
    return nums;
}

vector<int> rightRotate(vector<int>& nums, int k) 
{
    int n = nums.size();
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n -k , nums.end());
    reverse(nums.begin(), nums.end());
    return nums;
}