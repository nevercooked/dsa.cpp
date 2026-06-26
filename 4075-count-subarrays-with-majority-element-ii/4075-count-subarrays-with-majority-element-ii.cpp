class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long   subArrays = 0;
        long long   prefixSum = 0;
        int         n         = nums.size();
        int         prefix    = n;
        vector<int> freqs(n * 2 + 1, 0);
        freqs[n] = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                prefixSum += freqs[prefix];
                prefix    += 1;
            }
            else {
                prefix    -= 1;
                prefixSum -= freqs[prefix];
            }
            freqs[prefix] += 1;
            subArrays     += prefixSum; 
        }
        return subArrays;
    }
};