#include <iostream>
#include <stack>
#include <vector>

using namespace std;
bool knows(int a, int b, vector<vector<int>>& M){
    return M[a][b];
}

int celebrity(vector<vector<int>>& M, int n){
    stack<int> st;
    for(int i = 0; i < n; i++){
        st.push(i);
    }

    while(st.size() > 1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if(knows(a,b,M) && !knows(b,a,M)){
            st.push(b);
        }
        else if (knows(b,a,M) && !knows(a,b,M)){
            st.push(a);
        }
    }
    if(st.empty()){
        return -1;
    }
    int potentialCeleb = st.top();

    for(int i = 0; i < n ; i++){
        if(i != potentialCeleb && M[i][potentialCeleb] == 0 || M[potentialCeleb][i] == 1)
            return -1;

    }
    return potentialCeleb;
}