class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        using Pair = std::pair<int, int>;
        auto comp = [](const Pair& p1, const Pair& p2) -> bool {
            return p1.second > p2.second;
        };
        std::unordered_map<int, int> freqs;
        std::vector<Pair>            pairs;
        std::vector<int>             top;
        for (const auto& n : nums) {
            freqs[n] += 1;
        }
        for (Pair p : freqs) {
            pairs.push_back(std::move(p));
        }
        std::sort(pairs.begin(), pairs.end(), comp);
        for (int i = 0; i < std::min(static_cast<std::size_t>(k), pairs.size()); ++i) {
            top.push_back(std::move(pairs[i].first));
        }
        return top;
    }
};