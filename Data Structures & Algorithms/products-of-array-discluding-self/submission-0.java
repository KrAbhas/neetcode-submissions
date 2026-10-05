class Solution {
    public int[] productExceptSelf(int[] nums) {
        int flag = 0;
        int prod = 1;
        for (int num: nums) {
            if (num == 0) {
                flag++;
                continue;
            }
            prod = prod * num;
        }
        for (int i = 0; i < nums.length; i++) {
            if (flag > 1) {
                nums[i] = 0;
            }
            else if (flag == 1) {
                if (nums[i] == 0)
                    nums[i] = prod;
                else nums[i] = 0;
            }
            else {
                nums[i] = prod / nums[i];
            }
        }
        return nums;
    }
}  
