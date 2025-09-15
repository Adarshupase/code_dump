#include <iostream>
#include <list> 
#include <unordered_map>
using namespace std;
/**
 * lru cache new LRUCache(2)
 * lruCache.put(1,1) = {1=1}
 * lruCache.put(2,2) = {1=1,2=2}
 * lruCache.get(1) = 1 
 * lruCache.put(3,3) = {1=1,3=3}
 * lruCache.get(2) = -1
 * lruCache.put(4,4) = {4=4,3=3}
 * lruCache.get(1) = -1
 * lruCache.get(3) = 3 
 * lruCache.get(4) = 4 
 */
class LRUCache {
private:
    int capacity;
    unordered_map<int,list<pair<int,int>>::iterator> addr;//value is the pointer to the corresponding node in the linked list
    list<pair<int,int>> lru;

public:
    LRUCache(int capacity){
        this->capacity = capacity;
    }
    int get(int key){
        if(addr.find(key) == addr.end()){
            return -1;
        }

        auto keyPos = addr[key];

        lru.splice(lru.begin(),lru,keyPos);
        return lru.front().second;

    }

    void put(int key, int value){
        if(addr.find(key) != addr.end()){
            auto keyPos = addr[key];
            lru.splice(lru.begin(),lru,keyPos);
            lru.front().second = value;
            return;
        }

        if(addr.size() == capacity){
            int backKey = lru.back().first;
            lru.pop_back();
            addr.erase(backKey);
        }

        lru.push_front({key,value});
        addr[key] = lru.begin();
    }



};