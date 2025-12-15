class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        for (const auto& n : nums) {
            if (seen.find(n) != seen.end()) {
                return true;
            }
            seen.insert(n);
        }
        return false;
    }
};