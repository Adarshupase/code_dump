#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;           
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* reverseList(ListNode* start){
    ListNode* prev = nullptr;
    ListNode* cur = start;
    while(cur){
        ListNode* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

bool isPalindrome(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* reverseHalf = reverseList(slow);
    while(reverseHalf){
        if(head->val != reverseHalf->val){
            return false;
        }
        head =head->next;
        reverseHalf = reverseHalf->next;
    }
    return true;

}