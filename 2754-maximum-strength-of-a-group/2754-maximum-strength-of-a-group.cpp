class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long strength = 1;
        int       idx      = nums.size() - 1;
        if (nums.size() == 1) {
            return nums[0];
        }
        std::sort(nums.begin(), nums.end());
        for (; idx >= 0 && nums[idx] >= 0; --idx) {
            if (nums[idx] != 0) {
                strength *= nums[idx];
            }
        }
        if (idx < 1 && nums[nums.size() - 1] == 0) {
            return 0;
        }
        for (int i = 1; i <= idx; i += 2) {
            if (nums[i] < 0 && nums[i - 1] < 0) {
                strength *= (nums[i] * nums[i - 1]);
            }
        }
        return strength;
    }
};