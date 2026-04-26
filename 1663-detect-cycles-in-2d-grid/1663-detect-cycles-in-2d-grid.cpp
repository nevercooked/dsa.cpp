class Solution {
    const vector<pair<int, int>> directions = {
        {  1,  0 },
        {  0,  1 },
        { -1,  0 },
        {  0, -1 },
    };
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        auto dfs = [&](this const auto& self, int i, int j, int pi, int pj) -> bool {
            if (i < 0 || j < 0 || i >= m || j >= n) {
                return false;
            }
            if (pi != -1 && pj != -1 && grid[i][j] != grid[pi][pj]) {
                return false;
            }
            if (visited[i][j]) {
                return true;
            }
            visited[i][j] = true;
            bool hasCycle = false;
            for (auto [u, v] : directions) {
                u += i;
                v += j;
                if (u != pi || v != pj) {
                    hasCycle |= self(u, v, i, j);
                }
            }
            return hasCycle;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && dfs(i, j, -1, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};