class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        auto dfs = [&](this const auto& self, int i, int j) -> int {
            cout << i << " " << j << endl;
            if (i < 0 || j < 0 || i >= m || j >= n) {
                return 1;
            }
            if (grid[i][j] == 0) {
                return 1;
            }
            if (visited[i][j]) {
                return 0;
            }
            visited[i][j] = true;
            return self(i + 1, j) + self(i - 1, j) + self(i, j + 1) + self(i, j - 1);
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return dfs(i, j);
                }
            }
        }
        return 0;
    }
};