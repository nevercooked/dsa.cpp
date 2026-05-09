class Solution {
private:
    struct Position {
        int i;
        int j;
        int val;
    };
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m      = grid.size();
        int n      = grid[0].size();
        int layers = min(m / 2, n / 2);
        for (int layer = 0; layer < layers; ++layer) {
            vector<Position> positions;
            for (int j = layer; j <= (n - 1 - layer); ++j) {
                positions.push_back({layer, j, grid[layer][j]});
            } 
            for (int i = layer + 1; i <= (m - 1 - layer); ++i) {
                positions.push_back({i, n - 1 - layer, grid[i][n - 1 - layer]});
            }
            for (int j = (n - 2 - layer); j >= layer; --j) {
                positions.push_back({m - 1 - layer, j, grid[m - 1 - layer][j]});
            }
            for (int i = (m - 2 - layer); i > layer; --i) {
                positions.push_back({i, layer, grid[i][layer]});
            }
            int rotation = k % positions.size();
            for (int i = 0; i < positions.size(); ++i) {
                auto p   = positions[i];
                int  idx = (positions.size() + i + rotation) % positions.size(); 
                grid[p.i][p.j] = positions[idx].val;
            }
        }
        return grid;
    }
};