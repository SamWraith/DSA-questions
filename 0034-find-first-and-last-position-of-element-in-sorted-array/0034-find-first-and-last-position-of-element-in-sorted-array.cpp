#include <bits/stdc++.h>
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        const int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        cout<<first<<endl;
        if(first != nums.size() && nums[first] == target) ans[0] = first;
        else return ans;
        const int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        ans[1] = last - 1;
        
        return ans;
    }
};