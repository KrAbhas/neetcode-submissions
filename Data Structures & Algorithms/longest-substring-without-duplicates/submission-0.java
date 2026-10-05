class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] charr = new int[1000];
        int n = s.length();
        int ans = 0;
        int a = 0;
        for (int i = 0; i < n; i++) {
            char tch = s.charAt(i);
            charr[tch - ' ']++;
            while (charr[tch - ' '] > 1) {
                --charr[s.charAt(a++) - ' '];
            }
            ans = Math.max(ans, i - a + 1);
        }
        return ans;
    }
}