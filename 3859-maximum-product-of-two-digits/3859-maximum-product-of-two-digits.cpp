class Solution {
public:
    int maxProduct(int n) {
        int m1 = 0;
        int m2 = 0;
        while (n != 0) {
            int r = n % 10;
            if (r >= m1) {
                m2 = m1;
                m1 = r;
            }
            else {
                m2 = max(m2, r);
            }
            n /= 10;
        }
        return m1 * m2;
    }
};