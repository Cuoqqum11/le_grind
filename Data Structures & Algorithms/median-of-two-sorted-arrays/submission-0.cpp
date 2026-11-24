class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sortedNums;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                sortedNums.push_back(nums1[i++]);
            } else {
                sortedNums.push_back(nums2[j++]);
            }
        }
        
        while(i < nums1.size()) sortedNums.push_back(nums1[i++]);
        while(j < nums2.size()) sortedNums.push_back(nums2[j++]);
        
        int n = sortedNums.size();
        int k = n / 2;
        if (n % 2 == 1) return sortedNums[k];                     
        return (sortedNums[k - 1] + sortedNums[k]) / 2.0; 
    }
};
