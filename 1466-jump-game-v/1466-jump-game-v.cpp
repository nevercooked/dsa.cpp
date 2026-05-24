class Solution {
public:
    int maxJumps(vector<int>& nums, int d) {
        int         n   = nums.size();
        vector<int> dp(n, -1);
        auto        dfs = [&](this const auto& self, int i) -> void {
            if (dp[i] != -1) {
                return;
            }
            dp[i] = 1;
            for (int j = i - 1; j >= 0 && nums[j] < nums[i] && (i - j) <= d; --j) {
                self(j);
                dp[i] = max(dp[i], dp[j] + 1);
            }
            for (int j = i + 1; j < n && nums[j] < nums[i] && (j - i) <= d; ++j) {
                self(j);
                dp[i] = max(dp[i], dp[j] + 1);
            }
        };
        for (int i = 0; i < nums.size(); ++i) {
            dfs(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};