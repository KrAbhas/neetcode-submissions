/* * APPROACH: Pure Range Search (l + 1 < r)
 * INVARIANT: One side is always sorted. We narrow the range to where target 'must' exist.
 * FAILURE TRIGGERS: Duplicate elements (not present here), target not in array.
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            // 1. Identify which half is perfectly sorted
            if (nums[l] < nums[mid]) { 
                // Left side is sorted. Is target inside this clean range?
                if (target >= nums[l] && target <= nums[mid]) r = mid;
                else l = mid;
            } 
            else { 
                // Right side is sorted. Is target inside this clean range?
                if (target >= nums[mid] && target <= nums[r]) l = mid;
                else r = mid;
            }
        }

        // 2. Post-processing: The loop only narrowed it down to two candidates
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        
        return -1;
    }
};