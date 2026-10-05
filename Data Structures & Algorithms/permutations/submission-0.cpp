/*
approach: we need to take different positions and maintain length. 
It can start at any position and cycle back to 0 using mod.
we need to keep a track if something has been taken, we shouldn't take them again

invariance: if we maintain the max length, this will be base condition. 
we can cover everything by cycling through the array. 
we can keep track using a hash/array if a position has been used
*/

class Solution {
private:
    vector<vector<int>> ans;
    void permute(vector<int> &nums, int n, vector<int> &hash, vector<int> &cur) {
        for (int i = 0; i < nums.size(); i++) {
            if (hash[i] == 1) continue;
            cur.push_back(nums[i]);
            hash[i] = 1;
            if (n == 1)
                ans.push_back(cur);
            else
                permute(nums, n - 1, hash, cur);
            cur.pop_back();
            hash[i] = 0;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n);
        vector<int> cur;
        permute(nums, n, hash, cur);
        return ans;
    }
};
