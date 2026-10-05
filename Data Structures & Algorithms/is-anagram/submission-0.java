class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        Map<Character, Integer> m = new HashMap<>();
        for (char ch: s.toCharArray()) {
            m.put(ch, m.getOrDefault(ch, 0) + 1);
        }
        for (char ch: t.toCharArray()) {
            int k = m.getOrDefault(ch, 0);
            if (k == 0) return false;
            m.put(ch, k - 1);
        }
        return true;
    }
}
