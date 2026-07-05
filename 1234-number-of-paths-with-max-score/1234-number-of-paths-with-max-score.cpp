class Solution {
private:
    static const int MOD = 1e9 + 7;

    struct Metadata {
        int score;
        int numberOfPath;
    };

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<Metadata>> dp(m, vector<Metadata>(n, { -1, 0 }));
        dp[m - 1][n - 1] = { 0, 1 };
        auto updateDP = [&](int i, int j, int k, int l) -> void {
            if (k >= m || l >= n || dp[k][l].score == -1) {
                return;
            }
            if (dp[k][l].score > dp[i][j].score) {
                dp[i][j] = dp[k][l];
                return;
            }
            if (dp[k][l].score == dp[i][j].score) {
                dp[i][j].numberOfPath += dp[k][l].numberOfPath;
                dp[i][j].numberOfPath %= MOD;
                return;
            }
        };
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (!(i == (m - 1) && j == (n - 1)) && board[i][j] != 'X') {
                    updateDP(i, j, i + 1, j);
                    updateDP(i, j, i, j + 1);
                    updateDP(i, j, i + 1, j + 1);
                    if (dp[i][j].score != -1) {
                        dp[i][j].score += (board[i][j] == 'E' ? 0 : board[i][j] - '0');
                    }
                }
            }
        }
        return (dp[0][0].score == - 1) ? vector<int>{ 0, 0 } : vector<int>{ dp[0][0].score, dp[0][0].numberOfPath };
    }
};