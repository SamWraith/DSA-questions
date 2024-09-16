class Solution {
private:
    int solve(int i){
        if(i == 0) return 1;
        if(i == 1) return 1;
        int left = solve(i - 1);
        int right = solve(i - 2);
        return left + right;
    }
    int mem(int i, vector<int> &dp){
        if(i == 0) return 1;
        if(i == 1) return 1;
        if(dp[i] != -1) return dp[i];
        int left = mem(i - 1, dp);
        int right = mem(i - 2, dp);
        dp[i] =  left + right;
        return dp[i];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        // return solve(n);
        return mem(n, dp);
    }
};