class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> elements;
        for (int i = 0; i < nums.size(); ++i) {
            int r = target - nums[i];
            if (elements.find(r) != elements.end())
                return { elements[r], i };
            elements[nums[i]] = i;
        }
        return {};
    }
};