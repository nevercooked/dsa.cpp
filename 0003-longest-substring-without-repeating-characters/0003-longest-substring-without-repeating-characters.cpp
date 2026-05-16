class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freqs;
        int len = 0;
        int i   = 0;
        for (int j = 0; j < s.size(); ++j) {
            freqs[s[j]] += 1;
            while (i <= j && freqs[s[j]] > 1) {
                freqs[s[i++]] -= 1;
            }
            len = max(len, j - i + 1);
        }
        return len;
    }
};