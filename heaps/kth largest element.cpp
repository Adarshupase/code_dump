#include <bits/stdc++.h>
using namespace std;

int KthLargestElement(vector<int> &arr, int k){
    priority_queue<int,vector<int>> pq;
    for(int i = 0 ; i < k-1; i++){
        pq.push(arr[i]);
    }
    for(int i = 0; i < k-1;i++){
        pq.pop();
    }
    return pq.top();
}