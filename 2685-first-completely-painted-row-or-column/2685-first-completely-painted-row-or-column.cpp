class Solution {
public:
    int firstCompleteIndex(std::vector<int>& nums, std::vector<std::vector<int>>& matrix) {
        using Position = std::pair<int, int>;
        std::vector<Position> positions(nums.size() + 1);
        std::vector<int>      rowsFreq(matrix.size(), 0);
        std::vector<int>      colsFreq(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                positions[matrix[i][j]] = std::make_pair(i, j);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            const auto& [irow, icol] = positions[nums[i]];
            rowsFreq[irow] += 1;
            colsFreq[icol] += 1;
            if (rowsFreq[irow] >= matrix[0].size() || colsFreq[icol] >= matrix.size()) {
                return i;
            }
        }
        return -1;
    }
};