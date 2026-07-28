class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freqs(26, 0);
        for (const auto& c : s) {
            freqs[c - 'a'] += 1;
        }
        stringstream ss;
        char         extension = -1;
        for (int i = 0; i < 26; ++i) {
            while (freqs[i] > 1) {
                char chr = 'a' + i;
                ss       << chr;
                freqs[i] -= 2;
            }
            if (freqs[i] == 1) {
                extension = 'a' + i;
            }
        }
        string left  = ss.str();
        string right = string(left.rbegin(), left.rend());
        return extension == -1 ? left + right : left + extension + right;
    }
};