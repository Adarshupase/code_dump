#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal)
{
    int i = 0;
    int cnt = 0;
    while (i < 32){
        int startBit = (start >> i) & 1;
        int goalBit  = (goal >> i) & 1;
        if(startBit != goalBit){
            cnt++;
        }
        i++;
    }
    return cnt;
    
}