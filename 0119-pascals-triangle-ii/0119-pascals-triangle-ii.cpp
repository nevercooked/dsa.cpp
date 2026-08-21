class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return { 1 };
        }
        vector<int> prevRow = { 1, 1 };
        for (int i = 2; i <= rowIndex; ++i) {
            int n = prevRow.size() + 1;
            vector<int> row(n, 1);
            for (int j = 1; j < n - 1; ++j) {
                row[j] = prevRow[j - 1] + prevRow[j];
            }
            prevRow = row;
        }
        return prevRow;
    }
};