class Solution {
public:
    int minimumLevels(vector<int>& states) {
        int total = std::accumulate(states.begin(), states.end(), 0, [](const int& a, const int& b) {return a + (b == 1 ? 1 : -1); });
        int accu  = 0;
        for (int i = 0; i < states.size() - 1; ++i) {
            int state = states[i];
            accu     += (state == 1 ? 1 : -1);
            if (2 * accu > total) return i + 1;
        }
        return -1;
    }
};