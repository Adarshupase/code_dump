#include <bits/stdc++.h>
using namespace std;

string infixToPostfix(string s)
{
    string ans = "";
    unordered_map<char,int> precedence;
    precedence['^'] = 3;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['+'] = 1;
    precedence['-'] = 1;

    stack<char> st;
    for(int i = 0 ; i < s.size() ; i++){
        if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9'))
        {
            ans.push_back(s[i]);
        }

        else if (s[i] == '('){
            //opening bracket encountered pop the elements till closing bracket is encountered
            while(!st.empty() && st.top() != '('){
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && st.top() !='(' && precedence[st.top()] >= precedence[s[i]]){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }

    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
};