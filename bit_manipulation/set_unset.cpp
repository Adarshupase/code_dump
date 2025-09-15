#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n){
    /**
     * power of two can checked by using this approach
     * a power of two would have only 1 bit set at the left
     * like 
     * 10000000
     * n-1 would be 
     * 01111111
     * so taking & would be 0(n & n -1)
     * but if it doesn't it is not a powerOf2 
     * if(n&n-1 ==0){return true} else return {false};
     */
    if (n <= 0){
        return false;
    }
    if(n & n-1){
        return false;
    }
    return true;
}

int setBit(int n){
    /**
     * to set a bit at from the end we can use
     * n + 1 would have the same bits as n but the first 0 bit from the right will be set as 1 so we or it with n+1
     * ex : 5 = 101
     *      6 = 111
     * 5 | 6 = 111(last bit set)
     * 
     */
    if(isPowerOfTwo(n+1)){
        return n;
    }
    int ans = n | n + 1;
    return ans;
}