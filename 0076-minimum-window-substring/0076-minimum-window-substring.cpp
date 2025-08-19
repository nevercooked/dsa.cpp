class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> freqs;
        std::unordered_map<char, int> currentFreqs;
        for (const auto& c : t) freqs[c] += 1;
        int  validated = 0;
        int  needed    = freqs.size();
        auto window    = std::make_pair(-1, s.size());
        int  i         = 0;
        for (int j = 0; j < s.size(); ++j) {
            currentFreqs[s[j]] += 1;
            if (freqs.find(s[j]) != freqs.end() && currentFreqs[s[j]] == freqs[s[j]]) {
                validated += 1;
            }
            while (validated == needed) {
                if ((j - i + 1) < (window.second - window.first + 1)) {
                    window.first  = i;
                    window.second = j;
                }
                currentFreqs[s[i]] -= 1;
                if (freqs.find(s[i]) != freqs.end() && currentFreqs[s[i]] < freqs[s[i]]) {
                    validated -= 1;
                }
                i += 1;
            }
        }
        return (window.first < 0 || window.second > s.size() - 1) ? "" : s.substr(window.first, window.second - window.first + 1);
    }
};