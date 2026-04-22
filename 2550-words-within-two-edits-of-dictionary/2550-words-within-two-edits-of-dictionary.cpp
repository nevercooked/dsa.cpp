class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> words;
        for (const auto& query : queries) {
            for (const auto& word : dictionary) {
                if (query.size() != word.size()) {
                    continue;
                }
                int diff = 0;
                for (int i = 0; i < word.size() && diff <= 2; ++i) {
                    if (query[i] != word[i]) {
                        diff += 1;
                    }
                }
                if (diff <= 2) {
                    words.push_back(query);
                    break;
                }
            }
        }
        return words;
    }
};