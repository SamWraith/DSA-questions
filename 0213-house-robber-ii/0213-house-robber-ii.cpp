class Solution {
private:
    int solve(int i, vector<int> &nums){
        if(i == 0) return nums[i];
        if(i < 0) return 0;

        int take = nums[i] + solve(i - 2, nums);
        int nottake = 0 + solve(i - 1, nums);
        return max(take, nottake);
    }
    int mem(int i, vector<int> &nums, vector<int> &dp){
        if(i == 0) return nums[i];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + mem(i - 2, nums, dp);
        int nottake = 0 + mem(i - 1, nums, dp);
        return dp[i] = max(take, nottake);
    }
    int tab(int n, vector<int> &nums){
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i<n; i++){
            int take = nums[i];
            if(i > 1)
                take += dp[i - 2];
            int nottake = 0 + dp[i - 1];
            dp[i] = max(take, nottake);
        }
        return dp[n - 1];
    }
    int space(int n, vector<int> &nums){
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i<n; i++){
            int take = nums[i];
            if(i > 1)
                take += prev2;
            int nottake = 0 + prev;
            int curr = max(take, nottake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i = 0; i<n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        // return max(solve(temp1.size() - 1, temp1), solve(temp2.size() - 1, temp2));
        // vector<int> dp1(n-1, -1);
        // vector<int> dp2(n-1, -1);
        // return max(mem(temp1.size() - 1, temp1, dp1), mem(temp2.size() - 1, temp2, dp2));
        return max(tab(temp1.size() , temp1), tab(temp2.size(), temp2));
    }
};