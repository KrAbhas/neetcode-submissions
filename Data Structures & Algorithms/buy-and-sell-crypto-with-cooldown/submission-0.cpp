class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n + 2, 0));
        dp[0][1] = -1001;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dp[0][i + 2] = max(dp[1][i] - prices[i], dp[0][i + 1]);
            dp[1][i + 2] = max(dp[0][i + 1] + prices[i], dp[1][i + 1]);
            ans = max(ans, dp[1][i + 2]);
        }
        return ans;
    }
};
