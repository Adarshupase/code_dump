#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int node){
    int left = 2 * node + 1;
    int right = 2 * node + 2;
    int largest = node;
    int n = arr.size();
    
    if(left < n && arr[left] > arr[largest]){
        largest = left;
        
    }
    if(right < n && arr[right] > arr[right]){
        largest = right;
    }
    if (largest != node ){
        swap(arr[node],arr[largest]);
        heapify(arr,largest);
    }
    
}
void convertMinToMaxHeap(vector<int>& arr, int N) {
    for (int i = (N / 2) - 1; i >= 0; i--) {
        heapify(arr, i);
    }
}