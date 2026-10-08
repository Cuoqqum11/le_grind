class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() -1;

        while(l < r){
            int curSum = numbers[l] + numbers[r];

            if(curSum < target){
                l++;
            }
            else if(curSum > target){
                r--;
            }
            else{
                return {l + 1, r + 1};
            }
        }
        return {};
    }
};
