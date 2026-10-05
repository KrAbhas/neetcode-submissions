class Solution {
    public int longestConsecutive(int[] nums) {
        Arrays.sort(nums);
        Map<Integer, Integer> map = new HashMap<>();
        int[] len = new int[nums.length];
        int i = 0;
        int ans = 0;
        for (int num: nums) {
            int k = map.getOrDefault(num - 1, 0);
            map.put(num, k + 1);
            ans = Math.max(ans, k + 1);
        }
        return ans;
    }
}
