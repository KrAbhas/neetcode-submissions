class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        int minm = 0;
        int ans = nums[0];
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
            ans = max(ans, (pref[i + 1] - minm));
            minm = min(minm, pref[i + 1]);
        }
        return ans;
    }
};
