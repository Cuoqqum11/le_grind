class Solution {
public:
    int search(vector<int>& nums, int target) {
        double mid = nums.size() / 2;
        
        if(nums[mid] >= target){
            for(int i = mid; i >= 0; i--){
                if(nums[i] == target) {
                    return i;
                }
            }
        }
        if(nums[mid] < target){
            for(int i = mid; i < nums.size(); i++){
                if(nums[i] == target) {
                    return i;
                }
            }
        }
        return -1;
    }
};
