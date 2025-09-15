#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x) ,next(nullptr){}
};


ListNode* reverseLL(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr) {
        ListNode* frwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
    }
    return prev;
}

ListNode* addOne(ListNode* head){
    head = reverseLL(head);
    ListNode* curr = head;
    int carry = 1;
    ListNode* last ;
    while(curr){
        long sum = curr->val + carry;
        curr->val = sum % 10;
        carry = sum / 10;
        if(curr && !curr->next){
            last = curr;
        }
        curr = curr->next;
    }
    while(carry){
        last->next = new ListNode(carry%10);
        carry = carry/10;
        last = last->next;
    }
    head = reverseLL(head);
    return head;
}