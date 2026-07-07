class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x   = 0;
        int       acc = 1;
        while (n != 0) {
            if ((n % 10) != 0) {
                sum += (n % 10);
                x   += ((n % 10) * acc);
                acc *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};