class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n    = s.size();
        int j    = 0;
        int ones = count(s.begin(), s.end(), '1');
        vector<int> zeroes;
        while (j < n) {
            int i = j;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            if (s[i] == '0') {
                zeroes.push_back(j - i);
            }
        }
        if (zeroes.size() < 2) {
            return ones;
        }
        int maxLen = 0; 
        for (int i = 0; i < zeroes.size() - 1; ++i) {
            maxLen = max(maxLen, zeroes[i] + zeroes[i + 1]);
        }
        return ones + maxLen;
    }
};