class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = n - 1;
        int u = 0;
        int d = m - 1;
        while (result.size() < (n * m)) {
            for (int j = l; j <= r; ++j) {
                result.push_back(matrix[u][j]);
            }
            for (int i = u + 1; i <= d; ++i) {
                result.push_back(matrix[i][r]);
            }
            cout << "l = " << l << " r = " << r << endl;
            for (int j = r - 1; j >= l && u != d; --j) {
                cout << "[" << d << ", " << j << "]" << endl;
                result.push_back(matrix[d][j]);
            }
            for (int i = d - 1; i > u && l != r; --i) {
                result.push_back(matrix[i][l]);
            }
            l += 1;
            r -= 1;
            u += 1;
            d -= 1;
        }
        return result;
    }
};