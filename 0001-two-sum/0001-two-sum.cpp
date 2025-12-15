class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            const int r = target - nums[i];
            if (seen.find(r) != seen.end()) {
                return { seen[r], i };
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};