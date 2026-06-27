class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freqs;
        int                           n      = nums.size();
        int                           maxLen = 0;
        for (const auto& num : nums) {
            freqs[num] += 1;
        }
        maxLen = (freqs[1] % 2 == 0 ? freqs[1] - 1 : freqs[1]);
        freqs.erase(1);
        for (const auto& [num, _] : freqs) {
            int       currLen = 0;
            long long x       = num;
            for (; freqs.find(x) != freqs.end() && freqs[x] > 1; x *= x) {
                currLen += 2;
            }
            maxLen = max(
                maxLen,
                currLen + (freqs.find(x) != freqs.end()  && freqs[x] > 0 ? 1 : -1)
            );
        }
        return maxLen;
    }
};