class Solution {
public:
    bool isGood(vector<int>& nums) {
        int                n = nums.size() - 1;
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > n) {
                return false;
            }
            if (seen.find(nums[i]) != seen.end() && nums[i] != n) {
                return false;
            }
            seen.insert(nums[i]);
        }
        return seen.size() == n;
    }
};