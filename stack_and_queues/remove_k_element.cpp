#include <bits/stdc++.h>
using namespace std;

string remove_k_elements(string s, int k){
    stack<char> st;

    for (char c : s){
        while(!st.empty() && k > 0 && st.top() > c){
            st.pop();
            k--;
        }
        st.push(c);
    }
    while(!st.empty()){
        st.pop();
        k--;
    }

    string ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());

    while(!ans.empty() && ans.back() == '0'){
        ans.pop_back();
    }
    return ans.empty() ? "0" : ans;
}