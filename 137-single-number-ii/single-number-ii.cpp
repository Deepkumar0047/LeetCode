class Solution {
    public:
        int singleNumber(vector<int>& nums) {
                uint32_t ans = 0;

                        for (int i = 0; i < 32; i++) {
                                    int count = 0;

                                                for (int num : nums) {
                                                                uint32_t x = static_cast<uint32_t>(num);

                                                                                if ((x >> i) & 1U) {
                                                                                                    count++;
                                                                                                                    }
                                                                                                                                }

                                                                                                                                            if (count % 3 != 0) {
                                                                                                                                                            ans |= (1U << i);
                                                                                                                                                                        }
                                                                                                                                                                                }

                                                                                                                                                                                        return static_cast<int32_t>(ans);
                                                                                                                                                                                            }
                                                                                                                                                                                            };