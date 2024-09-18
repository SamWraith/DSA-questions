class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &triangle){
        if(i == (triangle.size()) - 1) return triangle[i][j];

        int down = triangle[i][j] + solve(i + 1, j, triangle);
        int diag = triangle[i][j] + solve(i + 1, j + 1, triangle);
        return min(down, diag);
    }
    int mem(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        if(i == (triangle.size()) - 1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + mem(i + 1, j, triangle, dp);
        int diag = triangle[i][j] + mem(i + 1, j + 1, triangle, dp);
        return dp[i][j] = min(down, diag);
    }
    int tab(vector<vector<int>> &triangle){
        int n = triangle.size();
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), -1));
        for(int i = 0; i<triangle[n - 1].size(); i++)
            dp[n - 1][i] = triangle[n - 1][i];
        for(int i = n - 2; i>= 0; i--){
            for(int j = i; j>=0; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }
    int space(vector<vector<int>> &triangle){
        int n = triangle.size();
        vector<int> next(n, 0);
        for(int i = 0; i<triangle[n - 1].size(); i++)
            next[i] = triangle[n - 1][i];
        for(int i = n - 2; i>= 0; i--){
            vector<int> curr(n, 0);
            for(int j = i; j>=0; j--){
                int down = triangle[i][j] + next[j];
                int diag = triangle[i][j] + next[j+1];
                curr[j] = min(down, diag);
            }
            next = curr;
        }
        return next[0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // return solve(0, 0, triangle);
        // vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), -1));
        // return mem(0, 0, triangle, dp);
        // return tab(triangle);
        return space(triangle);
    }
};