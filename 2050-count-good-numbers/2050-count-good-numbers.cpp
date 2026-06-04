class Solution {
public:
    int countGoodNumbers(long long n) {
        long long e   = (n / 2) + ((n % 2) == 0 ? 0 : 1);
        long long p   = n / 2; 
        long long mod = 1e9 + 7;
        auto      binexp = [&](long long x, long long exp) -> long long {
            long long res = 1;
            x %= mod;
            while (exp > 0) {
                if (exp & 1) {
                    res = (res * x) % mod;
                }
                x    = (x * x) % mod;
                exp >>= 1;
            }
            return res;
        };
        return (binexp(5, e) * binexp(4, p) % mod) % mod;
    }
};