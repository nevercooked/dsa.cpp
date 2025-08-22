class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int i       = 0;
        int longest = 1;
        int prev    = 0;
        for (int j = 1; j < s.size(); ++j) {
            if (s[j] == s[j - 1]) {
                if (prev) {
                    i = prev;
                }
                prev = j;
            }
            longest = std::max(longest, j - i + 1);
        }
        return longest;
    }
};