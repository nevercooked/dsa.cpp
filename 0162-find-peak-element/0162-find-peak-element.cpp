class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int left  = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                right = mid - 1;
            } else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) {
                left = left + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};