#include <bits/stdc++.h>

using namespace std;

bool isPossible(int mid, int A[], int N, int M) 
{
    int pos_m = 1;
    int temp = 0;

    for (int i = 0; i < N ; i++){
        if(temp + A[i] <= mid) {
            temp += A[i];
        }
        else{
            pos_m++;
            if(A[i] > mid) {
                return false;
            }
            temp = A[i];
        }
    }
    if(pos_m <= M){
        return true;
    }
    return false;
}

int findPages(int A[], int N, int M) {
    if (M > N) return -1;

    int low = INT_MAX, high = 0;
    int ans = -1;
    for(int i = 0; i<N ; i++) {
        low = min(low,A[i]);
        high +=  A[i];
    }
    while (low <= high ){
        int mid = low + (high - low) / 2;
        if(isPossible(mid,A,N,M)) {
            ans = mid ;
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }
}