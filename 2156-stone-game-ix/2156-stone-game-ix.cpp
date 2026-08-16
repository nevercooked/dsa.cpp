class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        unordered_map<int, int> freqs;
        for (const auto& stone : stones) {
            freqs[stone % 3] += 1;
        }
        if (freqs[0] % 2 == 0) {
            return freqs[1] > 0 && freqs[2] > 0;
        }
        return abs(freqs[1] - freqs[2]) > 2;
    }
};