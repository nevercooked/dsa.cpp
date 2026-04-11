class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int n = 0;
        int m = 0;
        int b = 1;
        while ((x & b) == 0) {
            b <<= 1;
        }
        for (const auto& num : nums) {
            if ((num & b) == 0) {
                n ^= num;
            }
            else {
                m ^= num;
            }
        }
        return { n, m };
    }
};