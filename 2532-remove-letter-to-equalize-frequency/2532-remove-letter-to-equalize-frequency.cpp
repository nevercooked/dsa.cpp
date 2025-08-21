class Solution {
public:
    bool equalFrequency(string word) {
        std::unordered_map<char, int> freqs;
        std::unordered_map<int, int> freqOfFreqs;
        for (const auto& c : word) {
            freqs[c] += 1;
        }
        for (const auto& [_, freq] : freqs) {
            freqOfFreqs[freq] += 1;
        }
        if (freqOfFreqs.size() == 1) {
            const auto& [freq, freqOfFreq] = *freqOfFreqs.begin();
            return freq == 1 || freqOfFreq == 1;
        }
        if (freqOfFreqs.size() == 2) {
            const auto& p1 = *freqOfFreqs.begin();
            const auto& p2 = *std::next(freqOfFreqs.begin());
            if ((p1.first == 1 && p1.second == 1) || (p2.first == 1 && p2.second == 1)) {
                return true;
            }
            if (std::abs(p1.first - p2.first) == 1) {
                if (p1.first > p2.first) {
                    return p1.second == 1;
                }
                else {
                    return p2.second == 1;
                }
            } 
        }
        return false;
    }
};