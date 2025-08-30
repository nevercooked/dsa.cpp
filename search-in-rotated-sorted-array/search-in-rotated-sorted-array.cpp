class Solution {
public:
    int findMinimum(const std::vector<int>& nums) {
        int left  = 0;
        int right = nums.size() - 1; 
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums[nums.size() - 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int search(vector<int>& nums, int target) {
        int inflection = findMinimum(nums);
        int left       = target <= nums[nums.size() - 1] ? inflection : 0;
        int right      = target <= nums[nums.size() - 1] ? nums.size() - 1: std::max(0, inflection - 1);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};