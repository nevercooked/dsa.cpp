class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> freqs;
        for (const auto& num : nums) {
            freqs[num] += 1;
        }
        int maxLen = (freqs[1] % 2 == 0 ? freqs[1] - 1 : freqs[1]); 
        freqs.erase(1);
        for (const auto& [num, _] : freqs) {
            int currLen = 0;
            int x       = num;
            for (; freqs.find(x) != freqs.end() && freqs[x] > 1 && std::numeric_limits<int>::max() / x >= x; x *= x) {
                currLen += 2;
            }
            cout << x << endl;
            currLen += (freqs.find(x) != freqs.end() && freqs[x] > 0 ? 1 : -1); 
            maxLen   = max(maxLen, currLen);
        }
        return maxLen;
    }
};