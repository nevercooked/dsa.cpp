class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j && s[i] == s[j]) {
            i += 1;
            j -= 1;
            while (i <= j && s[i] == s[i - 1]) i +=1;
            while (i <= j && s[j] == s[j + 1]) j -=1;
        }
        return j - i + 1;
    }
};