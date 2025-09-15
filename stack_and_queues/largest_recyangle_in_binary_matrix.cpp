#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextSmaller(vector<int> &arr){
    //next smaller 
    stack<int> st;
    vector<int> ans(arr.size(), arr.size());

    for(int i = arr.size() ; i >= 0; i--){
        while(!st.empty() && arr[i] <= arr[st.top()]){
            st.pop();
        }
        if (!st.empty()){
            ans[i] = st.top();
        }

        st.push(i);
    }
    return ans;

}
vector<int> prevSmaller(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n,0);
    for(int i = 0; i < n ; i++){
        while (!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if (!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

int optimal_max_rectangle(vector<int> &arr){
    vector<int> prevS = prevSmaller(arr);
    vector<int> nextS = nextSmaller(arr);
    int ans = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        int width = nextS[i] - prevS[i] -1;
        ans = max(ans,width*arr[i]);
    }
    return ans;
}

int binary_matrix_max_rectangle(vector<vector<char>>& matrix){
    if(matrix.empty() || matrix[0].empty()){
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> prev(cols,0);
    int maxArea = 0;

    for(int i = 0; i < rows; i++){
        vector<int> curr(cols,0);
        for(int j = 0; j < cols; j++){
            if (matrix[i][j] == '1'){
                curr[j] = prev[j] + 1;
            }
        }
        int rowArea = optimal_max_rectangle(curr);
        maxArea = max(maxArea,rowArea);

        prev = curr;
    }
    return maxArea;
    
}