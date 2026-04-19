class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            int left  = i + 1;
            int right = nums2.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums2[mid] < nums1[i]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            if (right >= 0) {
                maxDist = max(maxDist, right - i);
            }
        }
        return maxDist;
    }
};