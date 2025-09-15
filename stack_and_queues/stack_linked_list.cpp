#include <bits/stdc++.h>
using namespace std;

class MyStack {
    private:
        struct StackNode {
        int data;
        StackNode* next;

        StackNode(int x) : data(x), next(nullptr) {}
    };
    StackNode* top;

    public:
        MyStack() : top(nullptr){}

        void push(int x);
        int pop();

};

void MyStack::push(int x){
    StackNode* temp = new StackNode(x);
    temp->next = top;
    top = temp;
}
int MyStack::pop() {
    if (!top)
        return -1;

    int popped = top->data;
    StackNode* temp = top;
    top = top->next;

    return popped;
}
