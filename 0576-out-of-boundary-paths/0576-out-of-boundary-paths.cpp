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
        auto dfs = [&](this const auto& self, const int i, const int j, const int moves) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n) {
                return 1;
            }
            if (moves == maxMove) {
                return 0;
            }
            if (dp[i][j][moves] != -1) {
                return dp[i][j][moves];
            }
            int paths = 0;
            for (const auto& [dx, dy] : directions) {
                paths = (paths + self(i + dx, j + dy, moves + 1)) % MOD;
            }
            return (dp[i][j][moves] = paths) % MOD;
        };
        return dfs(startRow, startColumn, 0);
    }
};