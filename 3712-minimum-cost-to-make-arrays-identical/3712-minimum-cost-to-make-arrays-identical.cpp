class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long min1 = 0;
        long long min2 = k;
        for (int i = 0; i < arr.size(); ++i) {
            min1 += std::abs(arr[i] - brr[i]);
        }
        std::sort(arr.begin(), arr.end());
        std::sort(brr.begin(), brr.end());
        for (int i = 0; i < arr.size(); ++i) {
            min2 += std::abs(arr[i] - brr[i]);
        }
        return std::min(min1, min2);
    }
};