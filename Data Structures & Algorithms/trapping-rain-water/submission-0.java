class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = 0;
            for (int j = i; j >= 0; j--) {
                a = Math.max(height[j], a);
            }
            int b = 0;
            for (int j = i; j < n; j++) {
                b = Math.max(height[j], b);
            }
            ans += Math.max(Math.min(a - height[i], b - height[i]), 0);
        }
        return ans;
    }
}
