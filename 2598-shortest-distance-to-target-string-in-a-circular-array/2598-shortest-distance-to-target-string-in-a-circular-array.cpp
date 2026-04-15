class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int closest = numeric_limits<int>::max();
        int n       = words.size();
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                closest = min(closest, min(dist, n - dist));
            }
        }
        return closest == numeric_limits<int>::max() ? -1 : closest;
    }
};