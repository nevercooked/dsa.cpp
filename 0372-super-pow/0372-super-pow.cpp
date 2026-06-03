class Solution {
public:
    int superPow(int a, vector<int>& b) {
        auto binpow = [](int x, int n, int m) {
            int res = 1;
            x %= m;
            while (n > 0) {
                if (n & 1) {
                    res = (res * x) % m;
                }
                x   = (x * x) % m;
                n >>= 1;
            }
            return res;
        };
        int res = binpow(a, b[0], 1337);
        for (int i = 1; i < b.size(); ++i) {
            res = binpow(res, 10, 1337);
            res = (res * binpow(a, b[i], 1337)) % 1337;
        }
        return res;
    }
};