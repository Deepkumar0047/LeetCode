class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
        return nums[0];

        int prev2 = 0;
        int prev1 = 0;

        for(int i =0;i < n;i++){
            int take = nums[i] + prev2;
            int skip = prev1;

            int curr = max(take,skip);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};