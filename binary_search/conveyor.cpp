#include <bits/stdc++.h>

using namespace std;

bool isPossible(int mid, vector<int>& weights, int days)
{
    int temp = mid, req_day = 1;

    for (auto it : weights) {
        if (it <= temp){
            temp -= it;
        }
        else{
            req_day++;
            if (it > mid) {
                return false;
            }
            temp = mid - it;
        }
    }
    if(req_day <= days){
        return true;
    }
    return false;
}

int shipWithinDays(vector<int>& weights, int days)
{
    int ans = -1;

    int low = INT_MAX, high = 0;

    for (auto it : weights){
        low = min(low,it);
        high += it;
    }
    //high means shipping all the package one by one 
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(isPossible(mid,weights,days)){
            ans = mid;
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}