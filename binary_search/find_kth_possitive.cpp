#include <bits/stdc++.h>

using namespace std;

int findKthPossitive(int arr[], int k) {
    int size = sizeof(arr)/sizeof(arr[0]);
    int low = 0, high = size-1;
    int pos = -1;
/**
 * find the possition in the array where count of missing elements becomes greater than 
 * k 
 */
    while (low <= high){
        int mid = low + (high - low) / 2;

        if ((arr[mid] - (mid + 1)) < k){
            low = mid + 1;
        } 
        else{
            pos = mid ;
            high = mid -1;
        }
    }
    if(pos == -1) return size + k;
    return pos + k;

}
/**
 * dry run 
 * arr = [2,3,4,7,11], k = 5
 * mid = 0 + 4 /2  = 2 arr[mid] = 4 , mid = 2 arr[mid] - mid + 1  = 3 < k yes 
 * low = mid + 1 low = 3 
 * mid = low + high / 2 = 3 + 4 = 7/2 = 3 if Arr[mid] - (4) = 7 - 4 = 3 < k yes
 * low = 4 mid = 3 + 1 arr[4] - (5) 11 - 5 = 6 else condition as 6 > k 
 * pos = 4 
 * return pos + 5 
 * 4 + 5 
 * = 9 
 * the 5th missing possitive integer is 9 
 * 
 */