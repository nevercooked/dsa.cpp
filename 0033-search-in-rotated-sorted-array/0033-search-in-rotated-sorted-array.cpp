class Solution {
public:
    int findMinimum(const std::vector<int>& nums) {
        int start = 0;
        int end   = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            (nums[mid] > nums[end]) ? start = mid + 1 : end = mid;
        }
        return start;
    }
    int search(vector<int>& nums, int target) {
        int inflection = findMinimum(nums);
        int start = 0;
        int end   = nums.size() - 1;
        (target <= nums[end]) ? start = inflection : end = inflection - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;
            (nums[mid] > target) ? end = mid - 1 : start = mid + 1;
        }
        return -1;
    }
};