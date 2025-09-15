#include <bits/stdc++.h>
using namespace std;
int calculate_platforms(vector<int> arri,vector<int> dep ,int n){
    sort(arri.begin(),arri.end());
    sort(dep.begin(),dep.end());
    
    int i = 0, j = 0,cnt = 0, maxcnt = 0;
    while(i < n){
        if(arri[i] < dep[j]){
            cnt = cnt + 1;
            i = i + 1;
        }
        else {
            cnt = cnt - 1;
            j = j + 1;
        }
        maxcnt =max(maxcnt,cnt);
    }
    return maxcnt;
    
}
static bool comp(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}
vector<int> jobSequencing(vector<vector<int>> & jobs){
     /**
     * each job has a id,deadline,reward 
     * we need to do the jobs to maximiize the reward 
     */
     int n = jobs.size();
     vector<pair<int,int>> jobPairs;
     for(auto job : jobs){
         jobPairs.push_back({job[1],job[2]});
     }
     sort(jobPairs.begin(), jobPairs.end(),comp);
     vector<int> deadline(n+1,-1);
     int cnt = 0, ans = 0;
     
     for(int i = 0; i < n; i++){
         int dead = jobPairs[i].first;
         int profit = jobPairs[i].second;
         
         while(dead >= 1 && deadline[dead] != -1){
             dead--;
         }
         if(dead >= 1){
             deadline[dead] = 1;
             cnt++;
             ans += profit;
         }
     }
     return {cnt,ans};
}
int main() {
    
}
