#include <bits/stdc++.h>

using namespace std;

string frequencySort(string s){
    unordered_map<char,int> mp;
    for(char c : s){
        mp[c]++;
    }
    priority_queue<pair<int,char>> pq;

    for(auto it : mp){
        pq.push({it.second,it.first});
    }

    string ans = "";
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        ans.append(cur.first,cur.second);
    }
}