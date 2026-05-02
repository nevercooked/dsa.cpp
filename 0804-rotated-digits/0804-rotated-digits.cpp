class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        auto canBeRotated = [](int i) -> int {
            bool rotated = false;
            while (i > 0) {
                int d = (i % 10);
                if (d == 3 || d == 4 || d == 7) {
                    return false;
                }
                if (!rotated && (d == 2 || d == 5 || d == 6 || d == 9)) {
                    rotated = true;
                }
                i /= 10;
            }
            return rotated;
        };
        for (int i = 1; i <= n; ++i) {
            if (canBeRotated(i)) {
                count += 1;
            }
        }
        return count;
    }
};