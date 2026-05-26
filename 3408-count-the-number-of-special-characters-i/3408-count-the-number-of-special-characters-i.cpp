class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cpt = 0;
        unordered_set<char> seen;
        vector<bool> done(26, false);
        for (const auto& c : word) {
            if (!done[tolower(c) - 'a'] && islower(c) && seen.find(toupper(c)) != seen.end()) {
                done[tolower(c) - 'a'] = true;
                cpt += 1;
            }
            if (!done[tolower(c) - 'a'] && isupper(c) && seen.find(tolower(c)) != seen.end()) {
                done[tolower(c) - 'a'] = true;
                cpt += 1;
            }
            seen.insert(c);
        }
        return cpt;
    }
};