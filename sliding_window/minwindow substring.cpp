#include <bits/stdc++.h>

using namespace std; 

string min_window(string s, string t){
    unordered_map<char,int> mp;

    for (auto it : t){
        mp[it]++;
    }

    int count = 0;
    int start = 0, min_len = INT_MAX;
    int substrBegin = 0;

    for (int i = 0; i < s.size(); i++){
        mp[s[i]]--;//decrease the count of the char in the map 
        
        if(mp[s[i]] == 0)
            count--;
        //decrease the count of that character as all the characters are in the window

        while (count == 0){
            // as all the characters are in the window
            if(i - start + 1 < min_len){
                substrBegin = start;
                min_len = i - start + 1;
            }

            mp[s[start]]++;
            //shrink the window from left and increase the count of that char in the 
            //map as it is no longer in the window
            if(mp[s[start]] > 0){
                count++;
            }

            start++;
        }
    }
}