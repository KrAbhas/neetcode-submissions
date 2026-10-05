class Solution {
public:
    vector<vector<int>> ans;
    void permutate(vector<int> &nums, vector<int> &cur, vector<bool> &hash, int n) {
        for (int i = 0; i < n; i++) {
            if (hash[i]) continue;
            hash[i] = true;
            cur.push_back(nums[i]);
            if ((int)cur.size() == n) 
                ans.push_back(cur);
            else
                permutate(nums, cur, hash, n);
            cur.pop_back();
            hash[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> hash(n, false);
        vector<int> cur;
        permutate(nums, cur, hash, n);
        return ans;
    }
};
