#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int data;
    ListNode* next;
    ListNode* prev;
    ListNode():data(0),next(nullptr),prev(nullptr){}
    ListNode(int x):data(x),next(nullptr),prev(nullptr){}
};

ListNode* removeDuplicates(ListNode* head)
{
    int dupli = head->data;
    ListNode* curr = head->next;

    while(curr){
        while(curr && curr->data == dupli){
            if(curr->next){
                curr->next->prev = curr->prev;
            }
            curr->prev->next = curr->next;
            curr = curr->next;

        }
        if(curr){
            dupli = curr->data;
            curr = curr->next;
        }
    }
    return head;
}