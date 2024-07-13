class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // lower bound
        int ans = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return ans;
    }
};