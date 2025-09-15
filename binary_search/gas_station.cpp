#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 

    int binarySearch(vector<int>& nums, int k) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == k){
            return mid;
        }
        else if (nums[mid] <= k) 
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
};

int main() {
    Solution s;
    int n, k ;
    cin >> n;
    cin >> k;
    vector<int> ques(n);
    for (int i = 0; i < n ; i++) {
        cin >> ques[i];
    }
    
    cout << s.binarySearch(ques,k)<< "\n";
}
bool isPossible(double mid, vector<int>& stations, int K)
{
    int req_stations = 0;
    for(int i = 1; i <stations.size(); i++){
        req_stations += (stations[i] - stations[i-1])/mid;

    }   
    return req_stations<= K;

}

double findSmallestDistance(vector<int>& stations, int K){
    double low = 0, high = stations[stations.size()-1] - stations[0];
    while(high - low > 1e-6){
        double 
    }
}
