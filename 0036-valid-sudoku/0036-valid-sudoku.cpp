class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (const auto& row : board) {
            std::unordered_set<char> seen;
            for (const auto& e : row) {
                if (!std::isdigit(e)) {
                    std::cout << e << std::endl;
                    continue;
                }
                if (seen.find(e) != seen.end()) {
                    return false;
                }
                seen.insert(e);
            }
        }
        for (int j = 0; j < board[0].size(); ++j) {
            std::unordered_set<char> seen;
            for (int i = 0; i < board.size(); ++i) {
                if (!std::isdigit(board[i][j])) {
                    continue;
                }
                if (seen.find(board[i][j]) != seen.end()) {
                    return false;
                }
                seen.insert(board[i][j]);
            }
        }
        const unsigned int size = 3;
        for (int square = 0; square < size * size; ++square) {
            std::unordered_set<char> seen;
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    const int row = (square / size) * 3 + i;
                    const int col = (square % size) * 3 + j;
                    if (!std::isdigit(board[row][col])) {
                        continue;
                    }
                    if (seen.find(board[row][col]) != seen.end()) {
                        return false;
                    }
                    seen.insert(board[row][col]);
                }
            }
        }
        return true; 
    }
};