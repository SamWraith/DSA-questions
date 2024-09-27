class Solution {
private:
    int solve(int i, int t, vector<int> &coins){
        if(i == 0){
            if(t % coins[0] == 0) return t / coins[0];
            else return 1e9;
        }
        int notTake = 0 + solve(i - 1, t, coins);
        int take = INT_MAX;
        if(t >= coins[i])
            take = 1 + solve(i, t - coins[i], coins);
        return min(take, notTake);
    }
    int mem(int i, int t, vector<int> &coins, vector<vector<int>> &dp){
        if(i == 0){
            if(t % coins[0] == 0) return t / coins[0];
            else return 1e9;
        }
        if(dp[i][t] != -1) return dp[i][t];
        int notTake = 0 + mem(i - 1, t, coins, dp);
        int take = INT_MAX;
        if(t >= coins[i])
            take = 1 + mem(i, t - coins[i], coins, dp);
        return dp[i][t] = min(take, notTake);
    }
    int tab(int n, int target, vector<int> &coins){
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        for(int t = 0; t <= target; t++){
            if(t % coins[0] == 0)
                dp[0][t] = t/coins[0];
            else dp[0][t] = 1e9;
        }
        for(int i = 1; i<n; i++){
            for(int t = 0; t<=target; t++){
                int notTake = 0 + dp[i - 1][t];
                int take = INT_MAX;
                if(t >= coins[i])
                    take = 1 + dp[i][t - coins[i]];
                dp[i][t] = min(take, notTake);
            }
        }
        int ans = dp[n-1][target];
        if(ans >= 1e9) return -1;
        else return ans;
    }
    int space(int n, int target, vector<int> &coins){
        vector<int> prev(target+1, 0), curr(target+1, 0);
        for(int t = 0; t <= target; t++){
            if(t % coins[0] == 0)
                prev[t] = t/coins[0];
            else prev[t] = 1e9;
        }
        for(int i = 1; i<n; i++){
            for(int t = 0; t<=target; t++){
                int notTake = 0 + prev[t];
                int take = INT_MAX;
                if(t >= coins[i])
                    take = 1 + curr[t - coins[i]];
                curr[t] = min(take, notTake);
            }
            prev = curr;
        }
        int ans = prev[target];
        if(ans >= 1e9) return -1;
        else return ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // return solve(n - 1, amount, coins);
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans =  mem(n - 1, amount, coins, dp);
        // if(ans >= 1e9) return -1;
        // return ans;
        
        // return tab(n, amount, coins);
        return space(n, amount, coins);



       
    }
};