#include <bits/stdc++.h>

using namespace std;


int upperBound(int arr[], int n, int x)
{
    int low = 0, high = n-1;

    int ans = -1;

    while (low <= high) 
    {
        int mid = low + (high-low) / 2;
        if(arr[mid] >= x) {
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    if(ans != -1) ans = arr[ans];
    return ans;
}