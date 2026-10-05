class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] charArr = new int[26];
        for (int i = 0; i < 26; i++) charArr[i] = 0;
        int i = 0;
        for (char ch: s.toCharArray()) {
            ++charArr[ch - 'a'];
            charArr[t.charAt(i) - 'a']--;
            i++;
        }
        for (i = 0; i < 26; i++) {
            if (charArr[i] != 0) return false;
        }
        return true;
    }
}
