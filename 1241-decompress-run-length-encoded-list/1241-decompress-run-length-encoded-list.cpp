class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> decompressed;
        for (int i = 1; i < nums.size(); i += 2) {
            int freq = nums[i - 1];
            int val  = nums[i];
            for (int j = 0; j < freq; ++j) {
                decompressed.push_back(val);
            }
        }
        return decompressed;
    }
};