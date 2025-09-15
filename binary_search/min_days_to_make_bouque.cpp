#include <bits/stdc++.h>
using namespace std;


//you need to use k adjacent flowers from the garden 

bool isPossible(int mid, vector<int>& bloomDay, int m , int k){
    int bqts = 0, temp = 0;
    for(auto it : bloomDay) {
        if(it <= mid){
            temp++;
        }
        else temp = 0;
        if(temp == k){
            bqts++;
                
            temp = 0;
        }
    }
    if(bqts >= m){
        return true;
    }
    return false;
}
int minDays(vector<int>& bloomDay, int m, int k)
{
    if((long)m*k > bloomDay.size()){
        return -1;
    }
    int ans = -1;

    int low  = INT_MAX, high = INT_MIN;

    for (auto it : bloomDay){
        low = min (low,it);
        high = max(high,it);
    }

    while(low <= high){
        int mid = low + ()
    }
}