class Solution {
private:
    int solve(int i, int j){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        int up = solve(i - 1, j);
        int down = solve(i, j - 1);
        return up + down;
    }
    int mem(int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = mem(i - 1, j, dp);
        int down = mem(i, j - 1, dp);
        return dp[i][j] = up + down;
    }
public:
    int uniquePaths(int m, int n) {
        // return solve(m - 1, n-1);
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return mem(m - 1, n - 1, dp);
    }
};