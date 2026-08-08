class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int         n    = word1.size();
        int         m    = word2.size();
        int         size = 0;
        int         j    =  m - 1;
        vector<int> suffix(n);
        for (int i = (n - 1); i >= 0; --i) {
            suffix[i] = size;
            if (j >= 0 && word1[i] == word2[j]) {
                j    -= 1;
                size += 1;
            }
        }
        vector<int> res;
        bool        used = false;
        j = 0;
        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                res.push_back(i);
                j += 1;
            }
            else if (!used && suffix[i] >= (m - j - 1)) {
                res.push_back(i);
                j   += 1;
                used = true;
            }
        }
        return (j == m ? res : vector<int>());
    }
};