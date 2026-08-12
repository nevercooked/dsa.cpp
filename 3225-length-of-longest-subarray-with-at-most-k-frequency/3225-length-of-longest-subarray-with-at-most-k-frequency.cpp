class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        int overflow = 0;
        int i = 0;
        int maxLen = 0;
        for (int j = 0; j < nums.size(); ++j) {
            freqs[nums[j]] += 1;
            if (freqs[nums[j]] > k) {
                overflow += 1;
            }
            while (i < j && overflow > 0) {
                freqs[nums[i]] -= 1;
                if (freqs[nums[i]] == k) {
                    overflow -= 1;
                }
                i += 1;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};