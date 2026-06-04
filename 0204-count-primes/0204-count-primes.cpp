class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; static_cast<long long>(i) * i < n; ++i) {
            if (!isPrime[i]) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        return count_if(isPrime.begin(), isPrime.end(), [](const auto& state) -> bool { return state == true; });
    }
};