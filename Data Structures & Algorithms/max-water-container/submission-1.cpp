class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0; int r = heights.size() - 1;
        int maxm = min(heights[l], heights[r]) * (r - l);
        while (l < r) {
            if (heights[l] <= heights[r]) l++;
            else r--;
            maxm = max(min(heights[l], heights[r]) * (r - l), maxm);
        }
        return maxm;
    }
};
