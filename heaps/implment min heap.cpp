#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    vector<int> pq;

    void heapify(int node){
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node  + 2;

        int smallest = node;

        if(leftChild < pq.size() && pq[leftChild] < pq[smallest])
            smallest = leftChild;
        if(rightChild < pq.size() && pq[rightChild] < pq[smallest])
            smallest = rightChild;
        if (smallest != node){
            swap(pq[node],pq[smallest]);
            heapify(smallest);
        }
    }
    void bottomUpHeapify(int node){
        int parent = (node - 1)/2;
        if(parent >= 0 && pq[parent] > pq[node]){
            swap(pq[parent],pq[node]);
            bottomUpHeapify(parent);
        }
    }

    void insert(int val){
        pq.push_back(val);
        bottomUpHeapify(pq.size()-1);
    }

    void removeMin(){
        pq[0] = pq.back();
        pq.pop_back();
        heapify(0);
    }

    int minElement(){
        return (pq.empty()) ? -1:pq[0];
    }
};
