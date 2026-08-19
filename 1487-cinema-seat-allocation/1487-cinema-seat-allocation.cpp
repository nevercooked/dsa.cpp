class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;
        for (const auto& seat : reservedSeats) {
            rows[seat[0]] |= (1 << seat[1]);
        }
        int families = 2 * (n - rows.size());
        constexpr int leftMask  = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); 
        constexpr int midMask   = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        constexpr int rightMask = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        for (const auto& [row, reserved] : rows) {
            bool left  = (reserved & leftMask) == 0;
            bool mid   = (reserved & midMask) == 0;
            bool right = (reserved & rightMask) == 0;
            families += left && right ? 2 : (left || mid || right);
        }
        return families;
    }
};