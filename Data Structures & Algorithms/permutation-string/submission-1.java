class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int[] charr = new int[256];
        int[] charrb = new int[256];
        int k = s1.length();
        int n = s2.length();
        if (n < k) return false;
        for (int i = 0; i < k; i++) {
            charr[s1.charAt(i)]++;
            charrb[s2.charAt(i)]++;
        }
        boolean isDone = true;
        for (int j = 0; j < k; j++) {
            if (charr[s1.charAt(j)] != charrb[s1.charAt(j)]) {
                isDone = false; break;
            }
        }
        if (isDone) return isDone;
        for (int i = 0; i < n - k; i++) {
            charrb[s2.charAt(i)]--;
            charrb[s2.charAt(i + k)]++;
            isDone = true;
            for (int j = 0; j < k; j++) {
                if (charr[s1.charAt(j)] != charrb[s1.charAt(j)]) {
                    isDone = false; break;
                }
            }
            if (isDone) return isDone;
        }
        return false;
    }
}