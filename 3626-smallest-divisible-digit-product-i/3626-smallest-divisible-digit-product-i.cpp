class Solution {
public:
    int smallestNumber(int n, int t) {
        int  i             = n;
        auto productDigits = [&](int x) {
            if (x == 0) {
                return 0;
            }
            int prod = 1;
            while (x != 0 && prod != 0) {
                prod *= (x % 10);
                x    /= 10;
            }
            return prod;
        };
        while (i < numeric_limits<int>::max()) {
            if (productDigits(i) % t == 0) {
                return i;
            }
            i += 1;
        }
        return -1;
    }
};