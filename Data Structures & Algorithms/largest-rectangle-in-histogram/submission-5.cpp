class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int best = 0;
        vector<int> left(n), right(n);

        for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) {
                left[i] = -1;
            } else {
                left[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(st.empty()) {
                right[i] = n;
            } else {
                right[i] = st.top();
            }
            st.push(i);
        }

        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            best = max(best, area);
        }

        return best;
    }
};
