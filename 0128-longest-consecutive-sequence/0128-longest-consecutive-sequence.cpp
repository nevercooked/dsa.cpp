class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        int                          longest = 0;
        for (const auto& n : s) {
            if (s.find(n - 1) == s.end()) {
                int i = 1;
                while (s.find(n + i) != s.end()) {
                    i += 1;
                }
                longest = std::max(longest, i);
            }
        }
        return longest;
    }
};