class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n   = matrix.size();
        int lim = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < lim; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            lim += 1;
        }
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};