class Solution {
    public int maxArea(int[] height) {
        int a = 0; int b = height.length - 1;
        int ans = 0;
        while (a < b) {
            ans = Math.max(ans, Math.min(height[a], height[b]) * (b - a));
            if (height[a] >= height[b]) b--;
            else a++;
        }
        return ans;
    }
}