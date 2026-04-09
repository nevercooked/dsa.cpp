class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int                    m   = grid.size();
        int                    n   = grid[0].size();
        int                    cpt = 0;
        vector<pair<int, int>> d  = {
            {  1,  0 }, 
            { -1,  0 },
            {  0,  1 },
            {  0, -1 },
        };
        vector<vector<bool>>   visited(m, vector<bool>(n, false));
        auto                   dfs = [&](this const auto& self,  int i, int j)  -> bool {
            if (i < 0 || j < 0 || i >= m || j >= n) {
                return false;
            }
            if (visited[i][j] || grid[i][j] == 1) {
                return true;
            }
            visited[i][j] = true;
            bool isClosed = true;
            for (auto [x, y] : d) {
                x += i;
                y += j;
                isClosed &= self(x, y);
            }
            return isClosed;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] == 0 && dfs(i, j)) {
                    cpt += 1;
                }
            }
        }
        return cpt;
    }
};