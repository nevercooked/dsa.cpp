class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m1 = numeric_limits<int>::max();
        int m2 = numeric_limits<int>::min();
        int r = grid[0][0] % x; 
        vector<int> nums;
        for (const auto& row : grid) {
            for (const auto& v : row) {
                if ((v % x) != r) {
                    return -1;
                }
                m1 = min(m1, v);
                m2 = max(m2, v);
                nums.push_back(v);
            }
        }
        sort(nums.begin(), nums.end());
        int median = (nums.size() / 2);
        int steps  = 0;
        for (const auto& n : nums) {
            steps += (abs(n - nums[median]) / x);
        }
        return steps;
    }
};