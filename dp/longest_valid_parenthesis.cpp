#include <bits/stdc++.h>

class Solution {
public:
    bool isMatch(std::string s, std::string p){
        int m = s.length();
        int n = s.length();

        std::vector<std::vector<bool>> dp(m+1,std::vector<bool>(n+1,false));
        dp[0][0] = true;

        for(int j = 1;j <= n; j++){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j-1];
            }
        }

        for(int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                if(p[j-1] == '*'){
                    //two possibilities for * 
                    // '*' matches an empty sequence ignore '*'
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];

                }else if(p[j-1] == '?' || s[i-1] == p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
    
};

class Solution2 {
    //for any bar at index i the water it can trap is determined by 
    // water_level - heigh[i]
    // Water_level is determined by the minimum of the tallest bar to the left and 
    // tallest bar to the right
public:
    int trap(std::vector<int>& height){
        if(height.empty()){
            return 0;
        }

        int left = 0;
        int right = height.size()-1;
        int left_max = 0;
        int right_max = 0;
        int total_water = 0;

        while (left < right){
            if(height[left] < height[right]){
                if(height[left] >= left_max){
                    left_max = height[left];
                }
                else{
                    total_water += left_max - height[left];
                }
                left++;
            }

            else{
                if(height[right] >= right_max) {
                    right_max = height[right];
                }
                else{
                    total_water += right_max - height[right];
                }
                right--;
            }
        }
        return total_water;
    }
};


class Solution3 {
public:
    int maxSubArray(std::vector<int>& nums) {

        int max_ans =  nums[0];
        int cur = nums[0];
        for(int i = 1; i < nums.size(); i++){
            cur = std::max(nums[i], cur + nums[i]);
            max_ans = std::max(cur,max_ans);
        }
        return max_ans;
    }
};


class Solution4 {
public:
    int jumpGame2(std::vector<int> &nums){
        int n = nums.size();
        if (n <= 1)
        {
            return 0;
        }
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        for (int i = 0; i < n -1 ; ++i){
            farthest = std::max(farthest,i + nums[i]);

            if (i == current_end){
                jumps++;
                current_end = farthest;

                if (current_end >= n -1){
                    break;
                }
            }
        }
    }
};

class Solution7 {
public:
    int uniquePaths(int m, int n){
        std::vector<std::vector<int>> dp(m,std::vector<int>(n,1));
        for(int i = 1; i <m ; i++){
            for(int j = 1; j < n ; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
class Solution5 {
public:
    int uniquePaths(int m,int n){
        std::vector<int> dp(n,1);

        for(int i  =1; i < m; i++){
            for(int j =1 ; j < n; j++){
                dp[j] = dp[j] + dp[j-1];
            }
        }
            return dp[n-1];

    }
};

class Solution6{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n  = obstacleGrid[0].size();

        std::vector<std::vector<int>> dp(m,std::vector<int>(n,0));
        if(obstacleGrid[0][0] == 1){
            return 0;
        }

        dp[0][0] = 1;

        for(int i = 1; i < m ; i++){
            if(obstacleGrid[i][0] == 0 && dp[i-1][0] == 1){
                dp[i][0] = 1;
            }else{
                dp[i][0] = 0;
            }
        }
        for(int j = 1; j < n ; j++){
            if(obstacleGrid[0][j] == 0 && dp[0][j] == 1){
                dp[0][j] = 1;
            }else{
                dp[0][j] = 0;
            }
        }

        for(int i = 1; i < m; i++ ){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};


int fib(int n){
    if(n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}

int main(){
    std::cout << fib(5) << "\n";
    return 0;
}


#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solutions;
        std::vector<std::string> board(n, std::string(n, '.')); // Initialize an empty n x n board
        solve(0, n, board, solutions);
        return solutions;
    }

private:
    // Checks if it's safe to place a queen at board[row][col]
    bool is_safe(int row, int col, int n, const std::vector<std::string>& board) {
        // Check the column upwards
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    // Recursive helper function to solve the puzzle
    void solve(int row, int n, std::vector<std::string>& board, std::vector<std::vector<std::string>>& solutions) {
        // Base case: If all queens are placed (we've reached the row after the last one)
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; ++col) {
            if (is_safe(row, col, n, board)) {
                board[row][col] = 'Q';    // Place the queen
                solve(row + 1, n, board, solutions); // Recur for the next row
                board[row][col] = '.';    // Backtrack: remove the queen to try other columns
            }
        }
    }
};