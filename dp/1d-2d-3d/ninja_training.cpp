#include <bits/stdc++.h>

using namespace std;

int f(int day,int last,vector<vector<int>>& points,vector<vector<int>>& dp)
{
    if(day == 0) {
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last){
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;

        
    }
    if (dp[day][last] != -1) return dp[day][last];
    int maxi = 0;

    for (int task = 0; task < 3; task++){
        if(task != last){
            int point = points[day][task] + f(day-1,task,points,dp);
            maxi = max(maxi,point);
        }
    }
    return dp[day][last] = maxi;
    

}
int ninjaTraining(int n, vector<vector<int>>& points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));

    f(n-1,3,points,dp);

}

int ninjaTraining2(int n, vector<vector<int>>& points)
{
    vector<int> prev(4,0);

    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][0],points[0][1]);
    prev[3] = max(points[0][0],max(points[0][1],points[0][2]));

    for (int day = 1; day < n ; day++){
        vector<int> temp(4,0);
        for(int last = 0; last < 4; last++){
            temp[last] = 0;
            for(int task = 0;task < 4; task++){
                if(task != last){
                int point = points[day][task] + prev[task];
                temp[task] = max(temp[task],point);
                }
            }

        prev = temp;
        }
    
    }
    return prev[3];
}
