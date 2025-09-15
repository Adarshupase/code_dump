#include <iostream>
#include<vector>
#include<stack>
using namespace std;

int getMaxArea(vector<int> &arr){
    int res= 0, n = arr.size();

    for(int i = 0; i < n ; i++){
        int curr = arr[i];

        for(int j = i - 1; j >= 0 && arr[j] >= arr[i]; j--){
            curr += arr[i];
        }

        for(int j = i + 1; j < n && arr[j] >= arr[i] ; j++){
            curr += arr[i];
        }

        res = max(res,curr);
    }
    return res;
}
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
int main(){
    vector<int> arr ={60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr);
    return 0;
}