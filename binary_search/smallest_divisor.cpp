#include <bits/stdc++.h>

using namespace std;

int smallestDivisor(vector<int>& nums, int threshold)
{
    int ans = -1;
    int low = 1 , high = INT_MIN;

    for(auto it : nums){
        high = max(high,it);
    }
    while (low <= high){
        int mid = low + (high - low)/2;
        int sum = 0;
        for(auto num : nums){
            sum += (num + mid - 1) / mid;

        }
        if (sum <= threshold){
            ans = mid ;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

