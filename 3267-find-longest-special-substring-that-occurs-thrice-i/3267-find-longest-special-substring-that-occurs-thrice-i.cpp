class Solution {
public:
    int maximumLength(std::string s) {
        std::unordered_map<std::string, int> freqs;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (j > i && s[j] != s[j - 1]) {
                    break;
                }
                std::string ss = s.substr(i, j - i + 1);
                freqs[ss] += 1;
            }
        }
        int longest = -1;
        for (const auto& [ss, freq] : freqs) {
            if (freq >= 3) {
                longest = std::max(longest, static_cast<int>(ss.size()));
            }
        }
        return longest;
    }
};