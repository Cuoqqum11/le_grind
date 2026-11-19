class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(nums[m] == target) return m;

            if (nums[l] <= nums[m]) {              // LEFT half is sorted
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;                     // target's in there → go left
                } else {
                    l = m + 1;                     // not in there → go right
                }
            } else {                               // RIGHT half is sorted
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;                     // target's in there → go right
                } else {
                    r = m - 1;                     // not in there → go left
                }
            }
        }
        return -1;
    }
};
