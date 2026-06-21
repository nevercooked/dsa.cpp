class Solution {
private:
    static constexpr int MOD = 1e9 + 7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<pair<int, int>> directions = {
            {  1,  0 },
            { -1,  0 },
            {  0,  1 },
            {  0, -1 },
        };
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        auto dfs = [&](this const auto& self, int i, int j, int moves) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n) {
                return 1;
            }
            if (dp[i][j][moves] != -1) {
                return dp[i][j][moves];
            }
            int paths = 0;
            for (auto [x, y] : directions) {
                x += i;
                y += j;
                if (moves + 1 <= maxMove) {
                    paths = (paths + self(x, y, moves + 1)) % MOD;
                }
            }
            return (dp[i][j][moves] = paths) % MOD;
        };
        return dfs(startRow, startColumn, 0);
    }
};