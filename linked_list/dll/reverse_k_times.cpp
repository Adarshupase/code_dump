#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode* prev;
    ListNode():data(0),next(nullptr),prev(nullptr){}
    ListNode(int x):data(x),next(nullptr),prev(nullptr){}
};

int findLen(ListNode* head){
    ListNode* curr = head;
    int cnt = 1;
    while(curr->next){
        curr = curr->next;
        cnt++;
    }
    curr->next = head;
    return cnt;
}

ListNode* rotateRight(ListNode* head,int k){
    if(head == NULL || k == 0){
        return head;
    }
    int len = findLen(head);

    k = k % len;

    ListNode* curr = head;

    for (int i = 0; i < len-k-1; i++){
        curr = curr->next;
    }
    ListNode* newHead = curr->next;
    curr->next = NULL;
    return newHead;
}