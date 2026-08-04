class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>        missing;
        unordered_set<int> seen(nums.begin(), nums.end());
        int lower = *min_element(nums.begin(), nums.end());
        int upper = *max_element(nums.begin(), nums.end());
        for (int i = lower; i <= upper; ++i) {
            if (seen.find(i) == seen.end()) {
                missing.push_back(i);
            }
        }
        return missing;
    }
};