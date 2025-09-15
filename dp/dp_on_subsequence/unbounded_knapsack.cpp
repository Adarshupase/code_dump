#include <bits/stdc++.h>
using namespace std;



int f(int ind, vector<int>& wt,vector<int>& val,int maxWeight)
{
    if(ind == 0) {
        return (maxWeight/wt[0]) * val[0];
    }
    int notTake = f(ind - 1, wt,val,maxWeight);
    int take = 0;
    if(maxWeight >= wt[ind]){
        take  = val[ind] + f(ind,wt,val,maxWeight-wt[ind]);
    }
    return max(take,notTake);
}
int unboundedKnapsack(int n, vector<int>& wt,vector<int>& val,int maxWeight)
{
    return f(n-1,wt,val,maxWeight);
}
