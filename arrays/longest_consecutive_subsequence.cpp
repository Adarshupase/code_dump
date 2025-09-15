#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSub(vector<int>& nums){
    // the problem is to find the longest consecutive subsequence
    //start from creating a set out of it 
    // set<int> would work fine as it is already sorted but we will use unordered set
    unordered_set<int> st(nums.begin(),nums.end());
    
    int ans = 0;
    for(auto num : st) {
        if(st.find(num-1) == st.end()){
            // meaning there are no preceding elements for this number start the count from here 
            int count = 0;
            while(st.find(num) != st.end()){
                count++;
                num++;
            }
            ans = max(count,ans);
        }
    }
    return ans;
        
}
