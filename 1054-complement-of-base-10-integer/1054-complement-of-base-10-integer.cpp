class Solution {
public:
    int bitwiseComplement(int n) {
        int m = 0;
        int b = 1;
        if (n == 0) {
            return 1;
        }
        for (int i = 0; i < numeric_limits<int>::digits && n != 0; ++i) {
            if ((n & 1) == 0) {
                m |= b;
            }
            n >>= 1;
            b <<= 1;
        }
        return m;
    }
};