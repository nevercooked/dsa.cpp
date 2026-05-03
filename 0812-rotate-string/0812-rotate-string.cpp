class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[0]) {
                continue;
            }
            int j = i;
            int k = 0;
            while (k < goal.size() && s[j] == goal[k]) {
                j  = (j + 1) % s.size();
                k += 1;
            }
            if (k == goal.size()) {
                return true;
            }
        }
        return false;
    }
};