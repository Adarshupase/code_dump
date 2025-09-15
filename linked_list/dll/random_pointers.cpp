#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode* random;
    ListNode():val(0),next(nullptr),random(nullptr){}
    ListNode(int x):val(x),next(nullptr),random(nullptr){}
};

ListNode* copyRandomList(ListNode* head){
    if(head == NULL){
        return head;
    }

    ListNode* orig = head;

    while(orig){
        ListNode* temp = orig->next;
        orig->next = new ListNode(orig->val);
        orig->next->next = temp;
        orig = orig->next->next;
    }
    orig = head;
    while(orig){
        if(orig->random && orig->next){
            orig->next->random = orig->random->next;
        }
        orig = orig->next;
    }
    orig = head;
    ListNode* ans = orig->next;
    while(orig && orig->next){
        ListNode* temp = orig->next->next;
        if(orig->next->next){
            orig->next->next = orig->next->next->next;
        }
        orig->next = temp;
        orig = orig->next;

    }
    return ans;
}