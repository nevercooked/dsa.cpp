class Solution {
public:
    int reachNumber(int target) {
        int moves = 0;
        int sum   = 0;
        target    = std::abs(target);
        while (sum < target || (sum - target) % 2 != 0) {
            moves += 1;
            sum   += moves;
        }
        return moves;
    }
};