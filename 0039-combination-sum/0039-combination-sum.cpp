class Solution {
public:
    void solve(int i, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> ds, int n){
        if(i == n){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(candidates[i] <= target){
            ds.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], ans, ds, n);
            ds.pop_back();
        }
        solve(i+1, candidates, target, ans, ds, n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        solve(0, candidates, target, ans, ds, n);
        return ans;

    }
};