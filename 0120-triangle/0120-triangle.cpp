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
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // return solve(0, 0, triangle);
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), -1));
        return mem(0, 0, triangle, dp);
    }
};