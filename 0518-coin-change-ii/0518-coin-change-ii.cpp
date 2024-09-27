class Solution {
private:
    int solve(int i, int t, vector<int> &coins){
        if(i == 0){
            return t % coins[0] == 0;
        }
        int notTake = solve(i - 1, t, coins);
        int take = 0;
        if(t >= coins[i])
            take = solve(i, t - coins[i], coins);
        return take + notTake;
    }
    int mem(int i, int t, vector<int> &coins, vector<vector<int>> &dp){
        if(i == 0){
            return t % coins[0] == 0;
        }
        if(dp[i][t] != -1) return dp[i][t];
        int notTake = mem(i - 1, t, coins, dp);
        int take = 0;
        if(t >= coins[i])
            take = mem(i, t - coins[i], coins, dp);
        return dp[i][t] = take + notTake;
    }
    int tab(int n, int target, vector<int> &coins){
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        for(int t = 0; t <= target; t++)
            dp[0][t] = (t % coins[0] == 0) ? 1 : 0;
        for(int i = 1; i<n; i++){
            for(int t = 0; t<= target; t++){
                int notTake = dp[i - 1][t];
                int take = 0;
                if(t >= coins[i])
                    take = dp[i][t - coins[i]];
                dp[i][t] = take + notTake;
            }
        }
        return dp[n - 1][target];
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // return solve(n - 1, amount, coins);
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return mem(n - 1, amount, coins, dp);
        // return tab(n, amount, coins);
    }
};