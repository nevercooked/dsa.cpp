class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int size = 1; size <= n; ++size) {
            for (int i = 0, j = size - 1; j < n; ++i, ++j) {
                int parity = (j + i + n) % 2;
                if (parity == 1) {
                    dp[i + 1][j + 1] = max(piles[i] + dp[i + 2][j + 1], piles[j] + dp[i + 1][j]);
                }
                else {
                    dp[i + 1][j + 1] = min(-piles[i] + dp[i + 2][j + 1], -piles[j] + dp[i + 1][j]);
                }
            }
        }
        return dp[1][n] > 0;
    }
};