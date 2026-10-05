class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> ans;
        for (int num: nums) {
            um[num]++;
        }
        for (auto& elmap: um) {
            bucket[elmap.second].push_back(elmap.first);
        }
        for (int i = nums.size(); i >= 0; i--) {
            for (int j = 0; j < bucket[i].size(); j++) {
                ans.push_back(bucket[i][j]);
                k--;
                if (k == 0)
                    return ans;
            }
        }

        return ans;
    }
};
