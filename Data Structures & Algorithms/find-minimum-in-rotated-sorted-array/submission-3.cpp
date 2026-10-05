class Solution {
private:
    bool is_left_shift(vector<int> &nums, int mid, int l, int r) {
        if (nums[mid] < nums[r]) return true;
        else return false;
    }
public:
    int findMin(vector<int> &nums) {
        int l = 0; int r = nums.size() - 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (is_left_shift(nums, mid, l, r)) 
                r = mid;
            else l = mid;
        }
        if (nums[l] < nums[r]) return nums[l];
        return nums[r];
    }
};
