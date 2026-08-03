class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, numeric_limits<int>::min());
        dp[n] = 0;
        for (int i = (n - 1); i >= 0; --i) {
            int sum = 0;
            for (int j = 1; j <= 3 && i + j <= n; ++j) {
                sum += stoneValue[i + j - 1];
                dp[i] = max(dp[i], sum - dp[i + j]);
            }
        }
        if (dp[0] > 0) {
            return "Alice";
        }
        if (dp[0] < 0) {
            return "Bob";
        }
        return "Tie";
    }
};