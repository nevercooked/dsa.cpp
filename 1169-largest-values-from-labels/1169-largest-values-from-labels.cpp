class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        std::unordered_map<int, int>     freqs;
        std::vector<std::pair<int, int>> pairs;
        int                              largest    = 0;
        int                               itemsCount = 0;
        for (int i = 0; i < values.size(); ++i) {
            pairs.push_back(std::make_pair(values[i], labels[i]));
        }
        std::sort(pairs.begin(), pairs.end(), std::greater<std::pair<int, int>>());
        for (int i = 0; i < pairs.size() && itemsCount < numWanted; ++i) {
            const auto& [value, label] = pairs[i];
            if (freqs[label] < useLimit) {
                freqs[label] += 1;
                largest      += value;
                itemsCount   += 1;
            }
        }
        return largest;
    }
};