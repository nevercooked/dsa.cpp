class Solution {
public:
    int divide(int dividend, int divisor) {
        int signDividend = (dividend >= 0 ? 1 : -1);
        int signDivisor  = (divisor >= 0 ? 1 : -1);
        int sign         = signDividend * signDivisor;
        int quotient     = 0;
        int sum          = 0;
        if (sign > 0 && divisor == 1 && dividend == numeric_limits<int>::min()) {
            return numeric_limits<int>::min();
        }
        if (dividend > 0) {
            dividend *= -1;
        }
        if (divisor > 0) {
            divisor *= -1;
        }
        int times = 1;
        int dd    = divisor;
        while ((dividend - sum) <= dd) {
            long long diff = numeric_limits<int>::min() - sum;
            if (diff > divisor) {
                break;
            }
            if (quotient == numeric_limits<int>::max()) {
                return (sign > 0 ? numeric_limits<int>::max() : numeric_limits<int>::min());
            }
            quotient += times;
            sum      += dd;
            if (dd > numeric_limits<int>::min() / 2 && times < numeric_limits<int>::max() / 2) {
                dd       *= 2;
                times    *= 2;
            }
        }
        while ((dividend - sum) <= divisor) {
            long long diff = numeric_limits<int>::min() - sum;
            if (diff > divisor) {
                break;
            }
            if (quotient == numeric_limits<int>::max()) {
                return (sign > 0 ? numeric_limits<int>::max() : numeric_limits<int>::min());
            }
            quotient += 1;
            sum      += divisor;
        }
        return sign * quotient;
    }
};