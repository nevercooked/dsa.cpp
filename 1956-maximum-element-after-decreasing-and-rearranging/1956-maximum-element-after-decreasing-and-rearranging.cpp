class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int         n          = arr.size();
        int         maxElement = 1;
        vector<int> freqs(n + 1, 0);
        for (const auto& num : arr) {
            freqs[min(num, n)] += 1;
        }
        for (int i = 2; i <= n; ++i) {
            maxElement = min(maxElement + freqs[i], i);
        }
        return maxElement;
    }
};