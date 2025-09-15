#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll  floorSqrt(ll x)
{
    ll low = 1, high = x;
    ll ans = -1;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (x == mid * mid) {
            return mid;
        }
        else if (mid * mid < x) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }


    }
    return ans;
}