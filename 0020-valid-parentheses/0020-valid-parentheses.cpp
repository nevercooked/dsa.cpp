class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mapping = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };
        for (const auto& c : s) {
            if (mapping.find(c) != mapping.end()) {
                stk.push(c);
                continue;
            }
            if (stk.empty() || mapping[stk.top()] != c) {
                return false;
            }
            stk.pop();
        }
        return stk.empty();
    }
};