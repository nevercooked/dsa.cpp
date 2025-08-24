class Solution {
public:
    long long subArrayRanges(std::vector<int>& nums) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int nmin = nums[i];
            int nmax = nums[i];
            for (int j = i; j < nums.size(); ++j) {
                nmin = std::min(nmin, nums[j]);
                nmax = std::max(nmax, nums[j]);
                sum += (nmax - nmin);
            }
        }
        return sum;
    }
};