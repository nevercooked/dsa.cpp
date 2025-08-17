class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        auto s       = std::unordered_set<int>(nums.begin(), nums.end()); 
        int  longest = 0;
        for (const auto& n : s) {
            if (s.find(n - 1) == s.end()) {
                int cpt = 1;
                while (s.find(n + cpt) != s.end()) {
                    cpt += 1;
                }
                longest = std::max(longest, cpt);
            }
        }
        return longest;
    }
};