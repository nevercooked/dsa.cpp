class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        sort(nums.begin(), nums.end());
        if (nums[0] != 1 || nums[nums.size() - 1] != n) {
            return false;
        }
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] != (nums[i - 1] + 1)) {
                return false;
            }
        }
        return true;
    }
};