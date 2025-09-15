#include <iostream>
#include <unordered_map>
#include <vector>

int totalFruits(int N, std::vector<int>& Fruits){
    std::unordered_map<int,int> mp;
    int ans = 0, start = 0;
    for(int i = 0 ; i < Fruits.size(); i++){
        mp[Fruits[i]]++;
        while(mp.size() > 2){
            
        }
    }
}