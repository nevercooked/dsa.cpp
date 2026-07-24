class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int m = max(0, *max_element(nums.begin(), nums.end()));
        int xorMax = 1; 
        while (xorMax <= m) {
            xorMax <<= 1;
        }
        vector<int> v(xorMax);
        vector<int> w(xorMax);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                v[nums[i] ^ nums[j]] = 1;
            }
        }
        for (int i = 0; i < xorMax; ++i) {
            if (!v[i]) {
                continue;
            }
            for (const auto& j : nums) {
                w[i ^ j] = 1;
            }
        }
        int res = 0;
        for (int i = 0; i < xorMax; ++i) {
            if (w[i]) {
                res += 1;
            }
        }
        return res;
    }
};