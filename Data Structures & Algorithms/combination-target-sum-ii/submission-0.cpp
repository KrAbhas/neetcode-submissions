class Solution {
private:
    vector<vector<int>> ans;
    void combinationSum(vector<int>& nums, int target, int ind, vector<int>& cur, int &sum) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i - 1] == nums[i]) continue;
            if (sum + nums[i] > target)
                continue;
            cur.push_back(nums[i]);
            sum += nums[i];
            combinationSum(nums, target, i + 1, cur, sum);
            sum -= nums[i];
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> cur = {};
        int sum = 0;
        combinationSum(nums, target, 0, cur, sum);
        return ans;
    }
};
