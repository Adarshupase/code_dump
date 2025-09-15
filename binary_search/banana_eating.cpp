#include <bits/stdc++.h>

using namespace std;
typedef long l;
bool isPossible(int mid,vector<int>& piles, int h) 
{
    l req = 0;
    for(auto it :piles){
        int time = it / mid;
        req += time;
        if(it % mid != 0) req++;
    }

    if (req <= h){
        return true;
    }
    return false;
}

int minEatingSpeed(vector<int>& piles, int h)
{
    int ans = -1;
    int low = 1, high = INT_MAX;
    for(auto it : piles) {
        int mid = low + (high-low)/2;
        if(isPossible(mid,piles,h)){
            ans = mid;
            high = mid -1;
        }
        else {
            low = mid +1;
        }
    }
    return ans;
}