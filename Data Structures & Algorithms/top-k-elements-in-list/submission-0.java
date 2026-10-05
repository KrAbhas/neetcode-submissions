class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Comparator<List<Integer>> comparator = (a, b) -> {
            int comp = Integer.compare(b.get(1), a.get(1));
            if (comp != 0) return comp;
            return Integer.compare(a.get(0), b.get(0));
        };
        SortedSet<List<Integer>> set = new TreeSet<>(comparator);
        Map<Integer, Integer> map = new HashMap<>();
        for (int num: nums) {
            int freq = map.getOrDefault(num, 0);
            map.put(num, freq + 1);
            if (set.contains(Arrays.asList(num, freq)))
                set.remove(Arrays.asList(num, freq));
            else if (set.size() >= k && set.last().get(1) < freq + 1)
                set.remove(set.last());
            if (set.size() < k) {
                set.add(Arrays.asList(num, freq + 1));
                // for (List<Integer> val: set) {
                //     System.out.print(val.get(0) + ":" + val.get(1) + " ");
                // }
                // System.out.println(set.last().get(0));
            }
        }
        int[] ans = new int[k];
        int i = 0;
        for (List<Integer> val: set) {
            ans[i++] = val.get(0);
        }
        return ans;
    }
}