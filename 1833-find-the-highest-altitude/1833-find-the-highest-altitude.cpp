class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int acc     = 0;
        for (const auto& y : gain) {
            acc    += y;
            highest = max(highest, acc);
        }
        return highest;
    }
};