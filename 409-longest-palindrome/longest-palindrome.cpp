class Solution {
    public:
        int longestPalindrome(string s) {
            int count[128] = {0};

            for (char c : s) {
                count[c]++;
            }

            int ans = 0;
            bool odd = false;

            for (int i = 0; i < 128; i++) {
                ans += (count[i] / 2) * 2;

                if (count[i] % 2 == 1) {
                    odd = true;
                }
            }

            if (odd)
            ans++;

            return ans;
        }
};