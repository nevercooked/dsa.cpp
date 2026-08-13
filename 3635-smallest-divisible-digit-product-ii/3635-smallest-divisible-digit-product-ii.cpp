class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long v = t;
        for (int i = 2; i <= 9; ++i) {
            while ((v % i) == 0) {
                v /= i;
            }
        }
        if (v > 1) {
            return "-1";
        }
        vector<long long> remaining(num.size() + 1);
        int               zero = num.size() - 1;
        remaining[0] = t;
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] == '0') {
                zero = i;
                break;
            }
            remaining[i + 1] = remaining[i] / gcd(remaining[i], num[i] - '0');
        }
        if (remaining[num.size()] == 1) {
            return num;
        }
        for (int i = zero; i >= 0; --i) {
            num[i] += 1;
            while (num[i] <= '9') {
                long long currRemaining = remaining[i] / gcd(remaining[i], num[i] - '0');
                int factor = 9;
                for (int j = num.size() - 1; j > i; --j) {
                    while ((currRemaining % factor) != 0) {
                        factor -= 1;
                    }
                    currRemaining /= factor;
                    num[j] = '0' + factor;
                }
                if (currRemaining == 1) {
                    return num;
                }
                num[i] += 1;
            }
        }
        string res;
        for (int i = 9; i > 1; --i) {
            while ((t % i) == 0) {
                res += '0' + i;
                t   /= i;
            }
        }
        res += string(max(static_cast<int>(num.size()) + 1 - static_cast<int>(res.size()), 0), '1');
        reverse(res.begin(), res.end());
        return res;
    }
};