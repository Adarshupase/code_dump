#include <iostream>
#include <unordered_map> 
#include <vector>
#include <string>
using namespace std;

int longest_substring_without_repeating_chars(string s){
    //keep index and char 
    int ans = 0;
    unordered_map<char,int> mp;

    int l = 0;
    for (int r = 0 ; r < s.size() ; r++){
        mp[s[r]]++;

        while(mp.size() < r - l  + 1){
            mp[s[l]]--;
            if (mp[s[l]] == 0){
                mp.erase(s[l]);
            }
            l++;
        }
        if(mp.size() == r - l + 1)
            ans = max(ans,r - l + 1);
    }
    return ans;
}
