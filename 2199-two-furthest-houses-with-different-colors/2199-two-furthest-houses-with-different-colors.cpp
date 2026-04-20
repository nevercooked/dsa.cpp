class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDist = 0;
        for (int i = colors.size() - 1; i > 0; --i) {
            if (colors[i] != colors[0]) {
                maxDist = max(maxDist, i);
                break;
            }
        }
        for (int i = 0; i < colors.size() - 1; ++i) {
            if (colors[i] != colors[colors.size() - 1]) {
                maxDist = max(maxDist, static_cast<int>(colors.size()) - 1 - i);
            }
        }
        return maxDist;
    }
};