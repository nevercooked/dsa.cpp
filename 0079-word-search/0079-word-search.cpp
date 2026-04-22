class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int, int>> directions = {
            {  0,  1 },
            {  1,  0 },
            {  0, -1 },
            { -1,  0 },
        };
        auto backtracking = [&](this const auto& self, int idx, int i, int j, vector<vector<bool>>& visited) -> bool {
            if (i < 0 || j < 0 || i >= m || j >= n) {
                return false;
            }
            if (visited[i][j]) {
                return false;
            }
            if (word[idx] != board[i][j]) {
                return false;
            }
            if (idx == word.size() - 1) {
                return true;
            }
            visited[i][j] = true;
            bool found = false;
            for (auto [x, y] : directions) {
                x     += i;
                y     += j;
                found |= self(idx + 1, x, y, visited);
            }
            visited[i][j] = false;
            return found;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    if (backtracking(0, i, j, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};