#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> triplet;

vector<int> mergeKArrays(vector<vector<int>>& arr, int K){
    priority_queue<triplet,vector<triplet>,greater<triplet>> pq;
    for(int i = 0; i < arr.size(); i++){
        pq.push({arr[i][0],{i,0}});
    }
    vector<int> merged;

    while (!pq.empty()){
        triplet mini = pq.top();
        pq.pop();

        merged.push_back(mini.first);

        int row = mini.second.first;
        int col = mini.second.second;

        if(col + 1 < K){
            pq.push({arr[row][col+1],{row,col+1}});
        }
    }
    return merged;
}