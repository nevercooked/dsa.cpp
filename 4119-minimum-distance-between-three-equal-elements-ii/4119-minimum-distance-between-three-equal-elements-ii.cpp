class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<int> indexes(nums.size());
        int         dist    = numeric_limits<int>::max();
        auto        compare = [&](int i, int j) -> bool {
            return (nums[i] == nums[j]) ? i < j : nums[i] < nums[j];
        };
        for (int i = 0; i < nums.size(); ++i) { indexes[i] = i; }
        sort(indexes.begin(), indexes.end(), compare);
        for (int x = 2; x < nums.size(); ++x) {
            int i = indexes[x];
            int j = indexes[x - 1];
            int k = indexes[x - 2];
            if (nums[i] == nums[j] && nums[i] == nums[k]) {
                dist = min(dist, 2 * (i - k));
            }
        }
        return dist == numeric_limits<int>::max() ? -1 : dist;
    }
};