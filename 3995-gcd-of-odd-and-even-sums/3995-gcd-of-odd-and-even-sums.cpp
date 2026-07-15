class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        auto gcd = [](this const auto& self, int x, int y) -> int {
            return y == 0 ? x : self(y, x % y);
        };
        return gcd(n * n, n * (n + 1));
    }
};