class Solution {
private:
    vector<int> computeLPS(const string_view& pattern) {
        int         n   = pattern.size();
        int         len = 0;
        int         idx = 1;
        vector<int> lps(n, 0); 
        while (idx < n) {
            if (pattern[idx] == pattern[len]) {
                len       += 1;
                lps[idx++] = len;
                continue;
            }
            if (len > 0) {
                len = lps[len - 1];
            }
            else {
                lps[idx++] = 0;
            }
        }
        return lps;
    }

    bool searchKMP(const string_view& text, const string_view& pattern) {
        vector<int> lps = computeLPS(pattern);
        int         i   = 0;
        int         j   = 0;
        int         n   = text.size();
        int         m   = pattern.size();
        while (i < n) {
            if (text[i] == pattern[j]) {
                i += 1;
                j += 1;
                if (j == m) {
                    return true;
                }
                continue;
            }
            if (j > 0) {
                j = lps[j - 1];
            }
            else {
                i += 1;
            }
        }
        return false;
    }
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        return searchKMP(s + s, goal);
    }
};