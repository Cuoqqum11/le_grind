class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for(char c : s1){
            need[c - 'a']++;
        }

        int m = s1.size();
        for(int i = 0; i < m; i++){
            window[s2[i] - 'a']++;
        }

        if(window == need){
            return true;
        }

        for(int r = m; r < s2.size(); r++){
            window[s2[r] - 'a']++;
            window[s2[r - m] - 'a']--;

            if(window == need) return true;
        }
        return false;
    }
};
