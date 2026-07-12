class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>                nums(arr.begin(), arr.end());
        unordered_map<int, int> rank;
        int                     i = 1;
        for (const auto& n : nums) {
            rank[n] = i++;
        }
        for (auto& el : arr) {
            el = rank[el];
        }
        return arr;
    }
};