class Solution {
private:
    long long computeSum(const long long& n) {
        return (n * (n + 1)) / 2;
    }
public:
    int arrangeCoins(int n) {
        int left  = 1;
        int right = n;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sum = computeSum(mid);
            if (sum <= n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};