/**
 * array by rank given an integer arr 
 * replace each integer with it's rank 
 * 
 */
 #include <bits/stdc++.h>
 using namespace std;
 
 vector<int> assignRank(vector<int>& nums){
     //use a min heap and start from 
     // so the smallest element will be on the top 
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     for(int i = 0 ; i < nums.size() ; i++){
         pq.push({nums[i],i});
     }
     int rank = 0;
     int prev = INT_MIN;
     vector<int> ans(nums.size()) ;
     while(!pq.empty()){
         auto ele = pq.top();
         pq.pop();
         if(ele.first != prev) {
             rank++;
         }
         ans[ele.second] = rank;
         prev = ele.first;
     }
     return ans;
 }
 int main() {
     int n;
     cin >> n;
     vector<int> ans(n);
     for(int i = 0 ; i < n; i++ ){
         cin >> ans[i];
     }
     //we have to assign the same rank to same numbers 
     vector<int> ret = assignRank(ans);
     for(int i = 0; i < ret.size() ; i++){
         cout << ret[i];
         cout << "\n";
     }
 }
 