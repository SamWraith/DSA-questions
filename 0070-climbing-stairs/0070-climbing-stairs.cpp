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
    int tab(int n){
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            int left = dp[i - 1];
            int right = dp[i - 2];
            dp[i] = left + right;
        }
        return dp[n];
    }
    int space(int n){
        // vector<int> dp(n+1, 0);
        int prev1 = 1;
        int prev2 = 1;
        for(int i = 2; i<=n; i++){
            int left = prev1;
            int right = prev2;

            int sum = left + right;
            prev2 = prev1;
            prev1 = sum;
        }
        return prev1;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        // return solve(n);
        // return mem(n, dp);
        // return tab(n);
        return space(n);
    }
};