class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        auto backtracking = [&](this const auto& self, int i, unordered_set<string>& seen) -> int {
            if (i == s.size()) {
                return 0;
            }
            int cpt = 0;
            for (int j = i; j < s.size(); ++j) {
                string sub = s.substr(i, j - i + 1);
                if (seen.find(sub) == seen.end()) {
                    seen.insert(sub);
                    cpt = max(cpt, 1 + self(j + 1, seen));
                    seen.erase(sub);
                }
            }
            return cpt;
        };
        return backtracking(0, seen);
    }
};