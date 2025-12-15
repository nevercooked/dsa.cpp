class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::unordered_map<char, int> freqs;
        for (int i = 0; i < s.size(); ++i) {
            freqs[s[i]] += 1;
            freqs[t[i]] -= 1;
        }
        for (const auto& [_, freq] : freqs) {
            if (freq != 0) {
                return false;
            }
        }
        return true;
    }
};