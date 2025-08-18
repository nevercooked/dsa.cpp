class Solution {
public:
    int maxArea(vector<int>& height) {
        int maximumArea = 0;
        int i           = 0;
        int j           = height.size() - 1;
        while (i < j) {
            maximumArea = std::max(maximumArea, static_cast<int>(std::abs(i - j) * std::min(height[i], height[j])));
            (height[i] > height[j]) ? j -= 1 : i += 1;
        }
        return maximumArea;
    }
};