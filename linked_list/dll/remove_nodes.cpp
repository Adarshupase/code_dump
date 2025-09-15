#include <bits/stdc++.h>
using namespace std;


struct ListNode{
    int data;
    ListNode* next;
    ListNode* prev;
    ListNode():data(0),next(nullptr),prev(nullptr){}
    ListNode(int x):data(x),next(nullptr),prev(nullptr){}
};
vector<pair<int,int>> findPairWithGievenSum(ListNode* head, int target)
{
    vector<pair<int,int>> ans;
    ListNode* start = head;
    ListNode* end = head;

    while(end->next){
        end = end->next;
    }
    while(start->data < end->data){
        int sum = start->data + end->data;
        if(sum == target){
            ans.push_back({start->data , end->data});
            start = start->next;
            end = end->prev;
        }
        else if(sum < target){
            start = start->next;
        }
        else{
            end = end->prev;
        }
    }
    return ans;
}