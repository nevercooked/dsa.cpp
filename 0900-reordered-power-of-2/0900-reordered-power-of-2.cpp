class Solution {
private:
    static constexpr std::array<int, 10> kPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    long long getSignature(int n) {
        long long signature = 1;
        if (n == 0) {
            return this->kPrimes[0];
        }
        while (n > 0) {
            signature *= this->kPrimes[n % 10];
            n         /= 10;
        }
        return signature;
    }
public:
    bool reorderedPowerOf2(int n) {
        long long targetSignature = getSignature(n);
        for (int i = 0; i <= 30; ++i) {
            long long signature = getSignature(1 << i);
            if (signature == targetSignature) {
                return true;
            }
        }
        return false;
    }
};