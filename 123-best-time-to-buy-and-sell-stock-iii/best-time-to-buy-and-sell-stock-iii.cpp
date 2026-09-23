class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(3,vector<int>(n,0));

        for(int t = 1; t <= 2; t++){
            int best = -prices[0];

            for(int i = 1;i < n;i++){
                dp[t][i] = max(dp[t][i-1],prices[i]+best);

                best = max(best,dp[t - 1][i] - prices[i]);
            }
        }
        return dp[2][n-1];
    }
};