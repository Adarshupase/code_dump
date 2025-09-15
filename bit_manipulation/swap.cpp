#include <bits/stdc++.h>
using namespace std;

pair<int,int> swapValues(int a, int b)
{
    /**  
     * a =  5 = 101
     * b = 9 = 1001
     * now xoring them gives 
     * 101^1001 = 1100(a)
     * b = 1100 ^ 1001 = 0101
     * a = 1100 ^ 0101 = 1001
     *
     */
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return {a,b};
}