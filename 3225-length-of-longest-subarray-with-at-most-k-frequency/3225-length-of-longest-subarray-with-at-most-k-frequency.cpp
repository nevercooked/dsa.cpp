class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        bool overflow = false;
        int  maxLen   = 0;
        int  i        = 0;
        for (int j = 0; j < nums.size(); ++j) {
            freqs[nums[j]] += 1;
            if (freqs[nums[j]] > k) {
                overflow = true;
            }
            while (i < j && overflow) {
                if (freqs[nums[i]] == (k + 1)) {
                    overflow = false;
                }
                freqs[nums[i]] -= 1;
                i              += 1;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};