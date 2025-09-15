#include <bits/stdc++.h>
using namespace std;

class MinStack {
    private:
        stack<long long> st;
        int mini;
    public:
        MinStack(){
            mini = -1;
        }

        void push(int val){
            if(st.empty()){
                st.push(0);
                mini = val;
            }
            else{
                st.push((long long)val-mini);
                // to get the top value just add to it the mini
                mini = min(val,mini);
                //mini keeps track of the current minimum element 
            }
        }
        void pop(){
            if(st.top() < 0){
                //if this is the minimum value in the array we need to have some new m
                //mini val
                mini = mini - st.top();
                /**
                 * [5,2,10]
                 * [0], mini = 5
                 * [0,-3] , mini = 2
                 * [0,-3,8], mini = 2
                 * once 10 is popped we have 
                 * [0,-3] 
                 * this is the minimum val so 
                 * now mini = mini = 2 - st.top(){-3}
                 * mini = 2 - (-3) = 5 
                 * this works because we did
                 * current_top - previous_mini = current_stack_val
                 * so previous_min = current_top - current_stack_val
                 * current_top = mini - st.top()
                 */
            }
            st.pop();
        }
        int top(){
            int ans = -1;
            if(st.top() < 0){
                ans = mini;
            }

            else{
                ans = mini + st.top();
            }
            return ans;
        }
        int getMin(){
            return mini;
        }
};
