class Solution {
private:
    bool is_left_shift(vector<int> &nums, int mid, int l, int r) {
        if (nums[mid] > nums[l]) return true;
        else return false;
    }
public:
    int findMin(vector<int> &nums) {
        int l = 0; int r = nums.size();
        if (r == 1 || nums[l] < nums[r - 1]) return nums[l];
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (is_left_shift(nums, mid, l, r)) 
                l = mid;
            else r = mid;
        }
        return nums[r];
    }
};
