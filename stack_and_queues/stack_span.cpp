#include <stack> 
#include <vector>
#include <iostream>

using namespace std;

vector<int> calculateSpan(vector<int> &arr){
    int n = arr.size();
    vector<int> span(n);
    stack<int> st;

    for(int i = 0; i < n ; i++){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }

        if(st.empty()){
            span[i] = i + 1;
        }
        else{
            span[i] = i - st.top();
        }
        st.push(i);
    }
    return span;
}