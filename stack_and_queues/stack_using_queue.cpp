#include <bits/stdc++.h>

class QueueStack{
    private:
        std::queue<int> q;
    
    public:
        void push(int x);

        int pop();

};

void QueueStack::push(int x){
    q.push(x);
}

int QueueStack::pop(){
    if (q.empty()) return -1;

    for(int i = 0 ; i < q.size(); i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    int popped = q.front();
    q.pop();
    return popped;
}