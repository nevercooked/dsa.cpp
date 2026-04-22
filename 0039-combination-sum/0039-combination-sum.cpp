class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>         vec;
        auto backtracking = [&](this const auto& self, vector<int>& v, int idx, int sum) -> void {
            if (sum == target) {
                res.push_back(v);
                return;
            }
            if (sum > target) {
                return;
            }
            for (int i = idx; i < candidates.size(); ++i) {
                int n = candidates[i];
                v.push_back(n);
                self(v, i, sum + n);
                v.pop_back();
            }
        };
        backtracking(vec, 0, 0);
        return res;
    }
};