class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (const auto& num : nums) {
            freqs[num] += 1;
        }
        int largest = -1;
        if (k == nums.size()) {
            largest = *max_element(nums.begin(), nums.end());
        }
        else if (k == 1) {
            for (const auto& num : nums) {
                if (freqs[num] == 1) {
                    largest = max(largest, num);
                }
            }
        }
        else {
            if (freqs[nums[0]] == 1) {
                largest = nums[0];
            }
            if (freqs[nums[nums.size() - 1]] == 1) {
                largest = max(largest, nums[nums.size() - 1]);
            }
        }
        return largest;
    }
};