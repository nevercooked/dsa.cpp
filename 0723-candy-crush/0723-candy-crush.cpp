class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        auto crush = [&]() -> bool {
            bool crushed = false;
            vector<vector<bool>> crush(m, vector<bool>(n, false));
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 2; j < board[0].size(); ++j) {
                    if (board[i][j] == board[i][j - 1] && board[i][j] == board[i][j - 2]) {
                        crush[i][j]     = true;
                        crush[i][j - 1] = true;
                        crush[i][j - 2] = true;
                    }
                }
            }
            for (int j = 0; j < board[0].size(); ++j) {
                for (int i = 2; i < board.size(); ++i) {
                    if (board[i][j] == board[i - 1][j] && board[i][j] == board[i - 2][j]) {
                        crush[i][j]     = true;
                        crush[i - 1][j] = true;
                        crush[i - 2][j] = true;
                    }
                }
            }
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[0].size(); ++j) {
                    if (crush[i][j]) {
                        board[i][j] = 0;
                        crushed     = true;
                    }
                }
            }
            return crushed;
        };
        auto gravity = [&]() -> bool {
            bool impact = false;
            for (int j = 0; j < board[0].size(); ++j) {
                int zero = -1;
                for (int i = (m - 1); i >= 0; --i) {
                    if (board[i][j] == 0) {
                        zero = max(zero, i);
                    }
                    else if (zero >= 0) {
                        swap(board[i][j], board[zero][j]);
                        zero -= 1;
                        impact = true;
                    }
                }
            }
            return impact;
        };
        while (crush() && gravity()) {}
        return board;
    }
};