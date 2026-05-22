class Solution {
private:
    int getPivot(const vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r]) {
                cout << "m = " << m << endl;
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return r;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot = getPivot(nums);
        int l     = (target > nums[nums.size() - 1] ? 0 : pivot);
        int r     = (target > nums[nums.size() - 1] ? pivot - 1 : nums.size() - 1);
        cout << pivot << endl;
        cout << l << "  " << r << endl;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return -1;
    }
};