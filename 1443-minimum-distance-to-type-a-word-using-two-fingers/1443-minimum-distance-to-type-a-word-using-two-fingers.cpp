class Solution {
public:
    int minimumDistance(string word) {
        vector<vector<int>> distances(26, vector<int>(26, 0));
        vector<string>      grid = {
            "ABCDEF",
            "GHIJKL",
            "MNOPQR",
            "STUVWX",
            "YZ"
        };
        for (int x1 = 0; x1 < grid.size(); ++x1) {
            for (int y1 = 0; y1 < grid[x1].size(); ++y1) {
                int pos1 = grid[x1][y1] - 'A';
                for (int x2 = 0; x2 < grid.size(); ++x2) {
                    for (int y2 = 0; y2 < grid[x2].size(); ++y2) {
                        int pos2 = grid[x2][y2] - 'A';
                        int dist = abs(x1 - x2) + abs(y1 - y2);
                        distances[pos1][pos2] = dist;
                    }
                }
            }
        }
        vector<vector<vector<int>>> dp(word.size(), vector<vector<int>>(26, vector<int>(26, numeric_limits<int>::max())));
        auto dfs = [&](this const auto& self, int idx, int first, int second) -> int{
            if (idx >= word.size()) {
                return 0;
            } 
            if (dp[idx][first][second] != numeric_limits<int>::max()) {
                return dp[idx][first][second];
            }
            char ch   = word[idx];
            int  pos  = ch - 'A'; 
            int  best = numeric_limits<int>::max();
            best                   = min(best, self(idx + 1, pos, second) + distances[first][pos]);
            best                   = min(best, self(idx + 1, first, pos) + distances[second][pos]);
            dp[idx][first][second] = best;
            return best;
        };
        int best = numeric_limits<int>::max();
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                best = min(best, dfs(0, i, j));
            }
        }
        return best;
    }
};