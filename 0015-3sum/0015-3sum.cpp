class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> v;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k];
                if (sum == 0) {
                    v.push_back({ nums[i], nums[j], nums[k] });
                    j += 1;
                    k -= 1;
                    while (j < k && nums[j] == nums[j - 1]) j += 1;
                    while (j < k && nums[k] == nums[k + 1]) k -= 1;
                }
                else if (sum < 0) {
                    j += 1;
                }
                else if (sum > 0) {
                    k -= 1;
                }
            }
        }
        return v;
    }
};