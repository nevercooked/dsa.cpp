class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> freqs;
        int                        pairs = 0;
        for (string word : words) {
            if (freqs.find(word) != freqs.end() && freqs[word] > 0) {
                pairs       += 1;
                freqs[word] -= 1;
            }
            reverse(word.begin(), word.end());
            freqs[word] += 1;
        }
        return pairs;
    }
};