class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<char, vector<int>> seen;
        int                              cpt = 0;
        for (int i = 0; i < word.size(); ++i) {
            seen[word[i]].push_back(i);
        }
        for (const auto& pattern : patterns) {
            for (auto i : seen[pattern[0]]) {
                int j = 0;
                while (i < word.size() && j < pattern.size()) {
                    if (word[i] != pattern[j]) {
                        break;
                    }
                    i += 1;
                    j += 1;
                }
                if (j == pattern.size()) {
                    cpt += 1;
                    break;
                }
            }
        }
        return cpt;
    }
};