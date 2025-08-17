class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<int, int> freqs;
        for (const auto& chr : s)
            freqs[chr] += 1;
        for (const auto& chr : t)
            freqs[chr] -= 1;
        for (const auto& [_, freq] : freqs) {
            if (freq != 0)
                return false;
        }
        return true;
    }
};