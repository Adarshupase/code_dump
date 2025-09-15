#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;           
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* startOfCycle(ListNode* slow, ListNode* fast)
{
    while(slow != fast){
        slow = slow->next;
        fast = fast->next->next;
}
    return slow;
}
ListNode* detectCycle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast= head;
    while(fast  && fast->next) {
        slow = slow -> next;
        fast = fast->next->next;
        if(slow == fast){
            fast = head;
            return startOfCycle(slow,fast);
        }
    }
}