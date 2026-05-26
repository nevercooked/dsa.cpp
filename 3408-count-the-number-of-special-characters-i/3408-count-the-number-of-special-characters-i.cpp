class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(), word.end());
        int cpt = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (s.find(c) != s.end() && s.find(toupper(c)) != s.end()) {
                cpt += 1;
            }
        }
        return cpt;
    }
};