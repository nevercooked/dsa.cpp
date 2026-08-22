class Solution {
public:
    bool checkDivisibility(int n) {
        auto sumDigits = [](int x) -> int {
            int s = 0;
            while (x != 0) {
                s += (x % 10);
                x /= 10;
            }
            return s;
        };
        auto prodDigits = [](int x) -> int {
            int p = 1;
            while (x != 0) {
                if (x % 10 == 0) {
                    return 0;
                }
                p *= (x % 10);
                x /= 10;
            }
            return p;
        };
        return (n % (sumDigits(n) + prodDigits(n))) == 0;
    }
};