#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> height){
    int leftMax = INT_MIN;
    int rightMax = INT_MAX;
    int left = 0,right = height.size()-1;
    int ans = 0;

    while(left <= right){
        if(height[left] < height[right]){
            if(height[left] > leftMax){
                leftMax = height[left];
            }
            else {
                ans += leftMax - height[left];
            }
        }
        else{
            if(height[right] > rightMax){
                rightMax = height[right];
            }
            else{
                ans += rightMax - height[right];
            }
        }
    }
    return ans;
}