class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> freqs;
        int longest      = 0;
        int maxOccurence = 0;
        int i            = 0;
        for (int j = 0; j < s.size(); ++j) {
            freqs[s[j]] += 1;
            maxOccurence = std::max(maxOccurence, freqs[s[j]]);
            while (i < j && (j - i + 1 - maxOccurence) > k) {
                freqs[s[i]] -= 1;
                maxOccurence = std::max(maxOccurence, freqs[s[i++]]);
            }
            longest = std::max(longest, j - i + 1);
        }
        return longest;
    }
};