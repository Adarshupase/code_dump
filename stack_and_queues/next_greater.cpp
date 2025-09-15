#include <bits/stdc++.h>
using namespace std;

void nextGreaterStack(vector<int>& nums, unordered_map<int,int>& mp){
    stack<int> st;
    for(int i = nums.size()-1; i >=0; i--){
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();

        }
        if(!st.empty()){
            mp[nums[i]] = st.top();

        }
        st.push(nums[i]);

    }
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int,int> mp;
    nextGreaterStack(nums2,mp);

    vector<int> ans(nums1.size(),-1);

    for(int i = 0 ; i < nums1.size(); i++){
        if(mp.find(nums1[i])!= mp.end()){
            ans[i] = mp[nums1[i]];
        }
    }
}

/** 
 * start from the right and whenever the top of the stack is 
 */