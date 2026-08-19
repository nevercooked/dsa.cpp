class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> rows;
        for (const auto& seat : reservedSeats) {
            rows[seat[0]].insert(seat[1]);
        }
        int families = 2 * (n - rows.size());
        for (const auto& [row, reserved] : rows) {
            bool left  = true;
            bool mid   = true;
            bool right = true;
            for (int seat = 2; seat <= 5; ++seat) {
                if (reserved.find(seat) != reserved.end()) {
                    left = false;
                    break;
                }
            }
            for (int seat = 4; seat <= 7; ++seat) {
                if (reserved.find(seat) != reserved.end()) {
                    mid = false;
                    break;
                }
            }
            for (int seat = 6; seat <= 9; ++seat) {
                if (reserved.find(seat) != reserved.end()) {
                    right = false;
                    break;
                }
            }
            if (left && right) {
                families += 2;
            }
            else if (left || mid || right) {
                families += 1;
            }
        }
        return families;
    }
};