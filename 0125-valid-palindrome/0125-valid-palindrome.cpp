class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (!std::isalnum(s[i])) {
                i += 1;
                continue;
            }
            if (!std::isalnum(s[j])) {
                j -= 1;
                continue;
            }
            if (std::tolower(s[i]) != std::tolower(s[j])) {
                return false;
            }
            i += 1;
            j -= 1;
        }

        return true;
    }
};