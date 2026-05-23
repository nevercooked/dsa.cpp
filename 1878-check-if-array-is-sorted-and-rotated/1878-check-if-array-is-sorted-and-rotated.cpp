class Solution {
public:
    bool check(vector<int>& nums) {
        int n     = nums.size();
        int pivot = -1;
        int count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                pivot  = i;
                count += 1;
            }
        }
        if (count == 0) {
            return true;
        }
        if (count > 1) {
            return false;
        }
        for (int i = (pivot + 1) % n; i != pivot; i = (i + 1) % n) {
            if (nums[i] < nums[(i == 0 ? n - 1 : i - 1)]) {
                return false;
            }
        }
        return true;
    }
};