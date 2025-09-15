#include <bits/stdc++.h>
using namespace std;

int divideTwoInteger(int dividend, int divisor)
{

    /**
     * in this code keep a and b as dividend and divisor while the divident is greater than divisor 
     * check how many divisors can be substracted from the dividend and do them as a multiple of power of 2's
     * like 
     * 37 and 3 
     * 
     *37 when divided by 3 
     /**
      * it can go upto  3 * 2 ^ 3 = 24 
      * 37 - 24 = 13 
      * now 13 (8 -> 2 ^ 3) 
      * it can go upto 3 * 2 ^ 2 = 12 (4) 
      * remaining 1 
      * return as a = 1 which is greater than b which is 3 
      * ans is 8 + 4 = 12 (12 * 3 = 36)
      *  */ 
     
    if (dividend == divisor){
        return 1;
    }

    bool isNegative = ((dividend <= 0 && divisor > 0) || dividend >=0 && divisor < 0);
    int ans = 0;

    int a = abs(dividend);
    int b = abs(divisor);

    while (a >= b){
        int q = 1;
        while (a > (b << q)){
            q++;
        }
        ans += (1<<(q-1));
        a -= (b << (q-1));


    }
    return (isNegative)?-ans:ans;

}