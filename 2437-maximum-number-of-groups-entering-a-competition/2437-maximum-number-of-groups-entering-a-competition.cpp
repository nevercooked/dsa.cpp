class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        return std::floor((std::sqrt(1 + 8 * grades.size()) - 1) / 2);
    }
};