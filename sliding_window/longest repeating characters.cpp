#include <iostream>
#include <unordered_set>
#include <string>

int longest_repeating_characters(std::string s, int k){
    int ltrcount = 0;
    std::unordered_set<char> ltrs;
    int ans = 0;

    for(auto it : s){
        ltrs.insert(it);
    }

    for(auto ltr : ltrs){
        int ltrcount = 0;
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ltr){
                ltrcount++;
            }
            while((i - start + 1) - ltrcount > k){
                if(s[start] == ltr){
                    ltrcount--;
                }
                start++;
            }
            if(((i - start + 1) - ltrcount) <= k){
                ans = std::max(ans,i-start + 1);
            }
        }
    }
    return ans;
}