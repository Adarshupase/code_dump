#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int data;
    ListNode* next;
    ListNode* prev;
    ListNode():data(0),next(nullptr),prev(nullptr){}
    ListNode(int x):data(x),next(nullptr),prev(nullptr){}
};


ListNode* reverseKGroup(ListNode* head, int k){
    ListNode* ptr = head;
    for(int i = 0; i < k; i++){
        if(!ptr){
            return head;
        }
        ptr = ptr->next;
    }
    int count = k;
    ListNode* prev= NULL;
    ListNode* curr = head;
    ListNode* frwd = NULL;

    while(count && curr){
        frwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
        count--;
    }
    if(frwd)
        head->next = reverseKGroup(frwd,k);
    return prev;
}