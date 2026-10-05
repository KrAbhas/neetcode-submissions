class Solution {
private:
    vector<vector<int>> ans;
    void subsets(vector<int>& nums, int ind, vector<int> &cur) {
        ans.push_back(cur);
        for (int i = ind; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            subsets(nums, i + 1, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur = {};
        subsets(nums, 0, cur);
        return ans;
    }
};