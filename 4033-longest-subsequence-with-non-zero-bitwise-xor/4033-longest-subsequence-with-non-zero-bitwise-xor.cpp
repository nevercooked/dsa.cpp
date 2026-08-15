class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int  x       = 0;
        bool nonZero = false;
        for (const auto& num : nums) {
            x ^= num;
            if (num != 0 && !nonZero) {
                nonZero = true;
            }
        }
        if (x != 0) {
            return nums.size();
        }
        return nonZero ? nums.size() - 1: 0;
    }
};