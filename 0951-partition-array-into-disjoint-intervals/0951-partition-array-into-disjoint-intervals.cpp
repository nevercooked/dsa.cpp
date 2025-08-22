class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        std::vector<int> minimums(nums.size(), 0);
        std::vector<int> maximums(nums.size(), 0);
        minimums[nums.size() - 1] = nums[nums.size() - 1];
        maximums[0]               = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maximums[i] = std::max(maximums[i - 1], nums[i]);
        }
        for (int i = nums.size() - 2; i >= 0; --i) {
            minimums[i] = std::min(minimums[i + 1], nums[i]);
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (maximums[i] <= minimums[i + 1]) return i + 1;
        }
        return -1;
    }
};