/*
steps:
1. get i in nums1 to split, both nums1 and nums2 based on this
2. match if we have good split
3. get the median
*/

class Solution {
private:
    int inf = 1e6 + 1;
    bool good(int i, vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        int j = (m + n + 1) / 2 - i;
        int left = i > 0? arr1[i - 1]: -inf;
        int right = j < n? arr2[j]: inf;
        return left > right;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> &arr1 = m < n? nums1: nums2;
        vector<int> &arr2 = m < n? nums2: nums1;
        m = arr1.size(); n = arr2.size();
        int l = -1; int r = m + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (good(mid, arr1, arr2))
                r = mid;
            else l = mid;
        }
        int i = l;
        int j = (m + n + 1) / 2 - i;
        double ans;
        int left1 = i > 0? arr1[i - 1]: -inf;
        int right1 = i < m? arr1[i]: inf;
        int left2 = j > 0? arr2[j - 1]: -inf;
        int right2 = j < n? arr2[j]: inf;
        if ((m + n) % 2) {
            ans = max(left1, left2);
        }
        else {
            ans = (max(left1, left2) + min(right1, right2)) / 2.0;
        }
        return ans;
    }
};
