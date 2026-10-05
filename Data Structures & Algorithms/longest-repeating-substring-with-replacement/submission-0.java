class Solution {
    private boolean isBalanced(int[] f, int k) {
        int s = 0;
        int m = 0;
        for (int i = 0; i < 266; i++) {
            s += f[i];
            m = Math.max(f[i], m);
        }
        return (s - m) <= k;
    }

    public int characterReplacement(String s, int k) {
        int ans = 0;
        int a = 0;
        int[] f = new int[266];
        for (int i = 0; i < s.length(); i++) {
            f[s.charAt(i)]++;
            while (!isBalanced(f, k)) {
                f[s.charAt(a++)]--;
            }
            ans = Math.max(ans, i - a + 1);
        }
        return ans;
    }
}
