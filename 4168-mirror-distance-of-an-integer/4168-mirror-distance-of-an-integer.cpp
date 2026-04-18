class Solution {
public:
    int mirrorDistance(int n) {
        int m = 0;
        int x = n;
        while (x > 0) {
            m *= 10;
            m += (x % 10);
            x /= 10;
        }
        return abs(n - m);
    }
};