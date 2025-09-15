#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;           
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* left = head;
    ListNode* right = head;

    for(int i = 0; i < n; i++){
        right = right->next;
    }

    if(!right){
        return head->next;
    }

    while (right->next)
    {
        left = left->next;
        right = right->next;
    }
    left->next = left->next->next;
    return head;
    
}