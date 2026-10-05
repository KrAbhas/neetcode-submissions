class Solution {
private:
    bool should_right_shift(vector<int> &nums, int mid, int left, int right, int target) {
        if (nums[left] < nums[right]) {
            if (nums[mid] > target) return true;
        }
        else {
            if ((target <= nums[right] && nums[mid] < nums[right]) || (target > nums[right] && nums[mid] > nums[right])) {
                if (target < nums[mid]) return true;
            }
            else {
                if (nums[mid] < nums[right]) return true;
            }
        }
        return false;
    }
public:
    int search(vector<int>& nums, int target) {
        int l = 0; int r = nums.size() - 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            cout << l << " " << r << " " << mid << endl;
            if (should_right_shift(nums, mid, l, r, target)) r = mid;
            else l = mid;
        }
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        return -1;
    }
};
