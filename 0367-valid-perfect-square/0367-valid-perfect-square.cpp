class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        int j = num;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (mid == (num / mid) && num % mid == 0) {
                return true;
            }
            if (mid < num / mid) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
        return false;
    }
};