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

ListNode* sortList(ListNode* head)
{
    
    if (!head || !head->next){
        return head;
    }

    
}

ListNode* merge(ListNode* left,ListNode* right){
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    
    if(left->val < right->val) {
        left->next = merge(left->next,right);
        return left;
    }
    else{
        right->next = merge(left,right->next);
        return right;
    }

    
}

ListNode* mergeSort(ListNode* start)
{
    if(start == NULL || start->next == NULL){
        return start;
    }

    ListNode* slow = start;
    ListNode* fast = start->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* a = mergeSort(slow->next);
    slow->next = NULL;
    ListNode* b = mergeSort(start);

    return merge(a,b);
}