class Solution {
    void dfs(int idx, int sum, int target, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        if(sum == target) {
            ans.push_back(curr);
            return;
        }
        if (sum > target || idx >= static_cast<int>(nums.size())) {
            return;
        }

        curr.push_back(nums[idx]);
        dfs(idx, sum + nums[idx], target, nums, curr, ans);

        curr.pop_back();
        dfs(idx + 1, sum, target, nums, curr, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(0, 0, target, nums, curr, ans);
        return ans;
    }
};

