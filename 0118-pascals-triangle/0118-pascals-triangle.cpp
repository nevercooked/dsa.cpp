class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return {};
        }
        if (numRows == 1) {
            return {{1}};
        }
        vector<vector<int>> prevRows = generate(numRows - 1);
        vector<int> row(numRows, 1);
        for (int i = 1; i < numRows - 1; ++i) {
            row[i] = prevRows.back()[i - 1] + prevRows.back()[i];
        }
        prevRows.push_back(row);
        return prevRows;
    }
};