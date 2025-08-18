class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> freqs;
        int longest = 0;
        int i       = 0;
        for (int j = 0; j < s.size(); ++j) {
            freqs[s[j]] += 1;
            while (i < j && freqs[s[j]] > 1) freqs[s[i++]] -= 1;
            longest = std::max(longest, j - i + 1);
        }
        return longest;
    }
};