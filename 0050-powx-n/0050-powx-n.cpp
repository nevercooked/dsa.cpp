class Solution {
public:
    double myPow(double x, int n) {
        auto solver = [](this const auto& self, const double& x, const int& n) -> double {
            if (n == 0) {
                return 1;
            }
            double binpow = self(x, n / 2);
            return binpow * binpow * (n % 2 == 0 ? 1 : x);
        };
        double p = solver(x, n);
        return (n > 0 ? p : 1 / p);
    }
};