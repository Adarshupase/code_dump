#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
        stack<int> input;
        stack<int> output;
    public:
        void enqueue(int x);
        int deque();
    
};

void Queue::enqueue(int x){
    input.push(x);
}

int Queue::deque(){
    if(input.empty() && output.empty()){
        return -1;
    }

    if(output.empty()){
        while(!input.empty()){
            int temp = input.top();
            input.pop();
            output.push(temp);
        }

    }
    int dequed = output.top();
    output.pop();
    return dequed;

}