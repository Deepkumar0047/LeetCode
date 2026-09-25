class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
        return 0;

        int m = matrix.size();
        int n = matrix[0].size();

       vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == '1'){
                    if(j == 0)
                    dp[i][j] = 1;
                    else
                    dp[i][j] = dp[i][j-1]+1;
                }
            }
        } 
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(dp[i][j] == 0)
                continue;

                int minWidth = INT_MAX;

                for(int k =i;k >= 0;k--){
                    minWidth = min(minWidth,dp[k][j]);
                    int height = i - k + 1;
                    int area = minWidth * height;
                    ans = max(ans,area);
                } 
            }
        }
        return ans;
    }
};