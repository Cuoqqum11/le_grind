class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int streak = 0;

        for (int x : nums){
            if(mp.find(x) != mp.end()){
                continue;
            }

            int left = 0;
            int right = 0;

            if(mp.find(x - 1) != mp.end()){
                left = mp[x - 1];
            }

            if(mp.find(x + 1) != mp.end()){
                right = mp[x + 1];
            }

            int total = left + right + 1;
            
            mp[x] = total;
            mp[x - left] = total;
            mp[x + right] = total;

            streak = max(streak, total);
        }
        return streak;
    }
};
