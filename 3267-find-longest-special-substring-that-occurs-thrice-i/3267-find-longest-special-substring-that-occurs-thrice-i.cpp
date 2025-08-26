class Solution {
private:
    bool findSpecialSubstrings(const std::string& s, const int& x) {
        std::vector<int> freqs(26, 0);
        int              i = 0;
        for (int j = 0; j < s.size(); ++j) {
            while (s[i] != s[j]) {
                i += 1;
            }
            if (j - i + 1 >= x) {
                freqs[s[j] - 'a'] += 1;
            }
            if (freqs[s[j] - 'a'] > 2) {
                return true;
            }
        }
        return false;
    }
public:
    int maximumLength(const std::string& s) {
        int i = 1;
        int j = s.size();
        if (!findSpecialSubstrings(s, 1)) {
            return -1;
        }
        while (i + 1 < j) {
            int mid = (i + j) / 2;
            if (findSpecialSubstrings(s, mid)) {
                i = mid;
            }
            else {
                j = mid;
            }
        }
        return i;
    }
};