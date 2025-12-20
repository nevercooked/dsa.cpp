class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> ans = std::vector<int>(nums.size(), 1);
        int              acc = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] = acc;
            acc   *= nums[i];
        }
        acc = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; --i) {
            ans[i] *= acc;
            acc    *= nums[i];
        }
        return ans;
    }
};