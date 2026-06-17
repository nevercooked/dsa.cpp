class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for (const auto& c : s) {
            switch (c) {
                case '*':
                    if (len > 0) {
                        len -= 1;
                    }
                    break;
                case '#':
                    len *= 2;
                    break;
                case '%':
                    break;
                default:
                    len += 1;
            }
        }
        if ((k + 1) > len) {
            return '.';
        }
        for (int i = s.size() - 1; i >= 0; --i) {
            switch(s[i]) {
                case '*':
                    len += 1;
                    break;
                case '#':
                    if ((k + 1) > (len + 1) / 2) {
                        k -= (len / 2);
                    }
                    len = (len + 1) / 2;
                    break;                   
                case '%':
                    k = len - k - 1;
                    break;               
                default:
                    if ((k + 1) == len) {
                        return s[i];
                    }
                    else {
                        len -= 1;
                    }
            }
        }
        return '.';
    }
};