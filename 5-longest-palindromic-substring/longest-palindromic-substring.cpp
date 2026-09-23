class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        if(n <= 1)
        return s;

        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int start = 0;
        int maxLen = 1;

        for(int i = 0;i < n;i++){
            dp[i][i] = true;
        }
        for(int len = 2;len <= n;len++){
            for(int i = 0;i<= n - len;i++){
                int j = i + len -1;
                if(len == 2){
                    dp[i][j] = (s[i]==s[j]);
                }
                else{
                    dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];
                }
                if(dp[i][j] && len > maxLen){
                    start = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(start,maxLen);
    }
};