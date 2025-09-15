#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int data;
    ListNode* next;
    ListNode* bottom;
    ListNode():data(0),next(nullptr),bottom(nullptr){}
    ListNode(int x):data(x),next(nullptr),bottom(nullptr){}
};

ListNode* merge(ListNode* head1,ListNode* head2)
{
    if(head1 == NULL){
        return head2;

    }
    if(head2 == NULL){
        return head1;
    }
    if(head1->data < head2->data){
        head1->bottom = merge(head1->bottom,head2);
        return head1;
    }
    else{
        head2->bottom = merge(head1,head2->bottom);
        return head2;
    }
}
ListNode* flatten(ListNode* root)
{
    if(root == NULL){
        return root;
    }
    ListNode* left = root;
    ListNode* right = flatten(root->next);
    root->next = NULL;
    left = merge(left,right);
    return left;
}