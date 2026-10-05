class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int a = 0; int b = numbers.length - 1;
        while (a < b) {
            if (numbers[a] + numbers[b] > target) b--;
            else if (numbers[a] + numbers[b] < target) a++;
            else return new int[]{a + 1, b + 1};
        }
        return new int[0];
    }
}
