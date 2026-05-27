class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> seen;
        for (const auto& c : word) {
            if (islower(c) && seen.find(toupper(c)) != seen.end()) {
                seen[c] = 0;
                continue;
            }
            seen[c] += 1;
        }
        int cpt = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (seen[c] > 0 && seen[toupper(c)] > 0) {
                cpt += 1;
            }
        }
        return cpt;
    }
};