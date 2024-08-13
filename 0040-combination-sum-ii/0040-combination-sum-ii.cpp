class Solution {
public:
    void solve(int ind, vector<int> candidates, int target, vector<int> &ds, vector<vector<int>> &ans, int n){
        if(target == 0){
            // sort(ds.begin(), ds.end());
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i<n; i++){
            if(i > ind && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            solve(i+1, candidates, target - candidates[i], ds, ans, n);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        solve(0, candidates, target, ds, ans, n);
        return ans;
    }
};