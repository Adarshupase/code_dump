#include <bits/stdc++.h>

using namespace std;

// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

typedef long long ll;
int rev_pair = 0;

void merge(int start, int mid, int end, vector<int>& nums)
{
    int leftSize = mid - start + 1;
    int rightSize = end - start;
    vector<int> left(leftSize),right(rightSize);

    for(int  i =0 ; i < leftSize; i++)
    {
        left[i] = nums[start + i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        right[i] = nums[mid + 1 + i];
    }

    int m =0;

    for (int i = 0; i < leftSize; i++){
        while (m < rightSize && left[i] > (ll) 2 * right[m]){
            m++;
        }
        rev_pair += m;
    }
    int i = 0, j = 0, k = start;

    while (i < leftSize && j < rightSize) {
        if (left[i] > right[j])
        {
            nums[k++] = right[j++];
        }
        else{
            nums[k++] = left[i++];
        }
    }
    while (i < leftSize)
    {
        nums[k++] = left[i++];
    }
    while (j < rightSize)
    {
        nums[k++] = right[j++];
    }


}

void mergeSort(int start,int end, vector<int>& nums)
{
    if (start >= end){
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(start,mid,nums);
    mergeSort(mid + 1,end,nums);
    merge(start,mid,end,nums);
}
int reversePairs(vector<int>& nums)
{
   
    mergeSort(0,nums.size()-1,nums);
    return rev_pair;
}