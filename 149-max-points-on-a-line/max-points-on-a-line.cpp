class Solution {
    public:
        int maxPoints(vector<vector<int>>& points) {
                int n = points.size();

                        if (n <= 2)
                                    return n;

                                            int ans = 0;

                                                    for (int i = 0; i < n; i++) {
                                                                map<pair<int, int>, int> mp;
                                                                            int duplicates = 0;

                                                                                        for (int j = i + 1; j < n; j++) {
                                                                                                        int dx = points[j][0] - points[i][0];
                                                                                                                        int dy = points[j][1] - points[i][1];

                                                                                                                                        if (dx == 0 && dy == 0) {
                                                                                                                                                            duplicates++;
                                                                                                                                                                                continue;
                                                                                                                                                                                                }

                                                                                                                                                                                                                int g = gcd(abs(dx), abs(dy));

                                                                                                                                                                                                                                dx /= g;
                                                                                                                                                                                                                                                dy /= g;

                                                                                                                                                                                                                                                                if (dx < 0) {
                                                                                                                                                                                                                                                                                    dx = -dx;
                                                                                                                                                                                                                                                                                                        dy = -dy;
                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                                        if (dx == 0)
                                                                                                                                                                                                                                                                                                                                                            dy = 1;

                                                                                                                                                                                                                                                                                                                                                                            mp[{dx, dy}]++;
                                                                                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                                                                                                    int current = 0;

                                                                                                                                                                                                                                                                                                                                                                                                                for (auto &it : mp) {
                                                                                                                                                                                                                                                                                                                                                                                                                                current = max(current, it.second);
                                                                                                                                                                                                                                                                                                                                                                                                                                            }

                                                                                                                                                                                                                                                                                                                                                                                                                                                        ans = max(ans, current + duplicates + 1);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                                                                                                                                                                                        return ans;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            };