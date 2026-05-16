class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        int                     acc = 0;
        int                     sum = 0;
        freqs[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            acc        += nums[i];
            sum        += freqs[acc - k];
            freqs[acc] += 1;
        }
        return sum;
    }
};