class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> visited(26, 0);
        vector<int> freqs(26, 0);
        string      stk;
        for (const auto& c : s) {
            freqs[c - 'a']++;
        }
        for (const auto& c : s) {
            if (!visited[c - 'a']) {
                while (!stk.empty() && stk.back() > c) {
                    if (freqs[stk.back() - 'a'] > 0) {
                        visited[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    } else {
                        break;
                    }
                }
                visited[c - 'a'] = 1;
                stk.push_back(c);
            }
            freqs[c - 'a'] -= 1;
        }
        return stk;
    }
};