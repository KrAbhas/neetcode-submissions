class Solution {
    private class MapListObj {
        int[] freq;
        List<String> group;
        MapListObj(String str) {
            freq = new int[26];
            for (char ch: str.toCharArray()) {
                freq[ch - 'a']++;
            }
            group = new ArrayList<>();
            group.add(str);
        }

        public boolean matchAnagram(String str) {
            int[] tempFreq = new int[26];
            for (char ch: str.toCharArray()) {
                tempFreq[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (freq[i] != tempFreq[i]) return false;
            }
            return true;
        } 

        public void addToGroup(String str) {
            group.add(str);
        }

        public List<String> getGroup() {
            return group;
        }
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList<>();
        Map<String, MapListObj> mans = new HashMap<>();
        for (String str: strs) {
            // if anagram already in mans
            // find anagram and put str in mans key anagram
            // else put as a new anagram
            if (!findAndPut(mans, str)) {
                mans.put(str, new MapListObj(str));
            }
        }
        for (Map.Entry<String, MapListObj> entry: mans.entrySet()) {
            ans.add(entry.getValue().getGroup());
        }
        return ans;
    }

    private boolean findAndPut(Map<String, MapListObj> mans, String str) {
        for (Map.Entry<String, MapListObj> entry: mans.entrySet()) {
            if (entry.getKey().length() != str.length()) continue;
            MapListObj obj = entry.getValue();
            if (!obj.matchAnagram(str)) continue;
            obj.addToGroup(str);
            return true;
        }
        return false;
    }
}
