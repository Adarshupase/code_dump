#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int>& arr){
    stack<int> st;
    vector<int> ans(arr.size(),-1);

    for (int i = 0; i < arr.size(); i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }

    return ans;
}