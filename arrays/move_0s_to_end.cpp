#include <bits/stdc++.h>

using namespace std;
/**
 * ans is simple for each num in the array 
 * is the num is 0 find the next non 
 * zero number and swap it with the next non zero number
 */
int nextNonZero(vector<int>& a, int j) {
    while (j < a.size())
    {
        if (a[j] != 0){
            return j;
        }
        j++;
    }
    return -1;
}

void moveZeroes(vector<int>& nums)
{
    int j = -1;
    for(int i = 0;i < nums.size(); i++)
    {
        if(nums[i] != 0){
            continue;
        }
        if(j == -1){
            j = i + 1;
        }
        int next = nextNonZero(nums,j);
        if(next == -1)
            return;
        swap(nums[i],nums[next]);
    }
}