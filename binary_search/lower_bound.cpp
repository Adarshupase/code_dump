#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int findFloor(vector<ll> v, ll n, ll x) {
    ll low = 0, high = n-1;
    int ans = -1;
    while (low <= high) {
        ll mid = low + (high-low)/2;
        if(v[mid] <= x) {
            ans = mid;
            low  = mid + 1;
        }
        else{
            high = mid -1;
        }

    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a;
    for(ll i = 0; i < n ; i++){
        cin >> a[i];
    }
    findFloor(a,n,4);    
}