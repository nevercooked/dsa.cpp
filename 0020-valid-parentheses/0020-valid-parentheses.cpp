class Solution {
public:
    bool isValid(string s) {
        std::stack<char>               stk;
        std::unordered_set<char>       openings = {'(', '{', '['};
        std::unordered_map<char, char> mapping  = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        for (const auto& c: s) {
            if (openings.find(c) != openings.end()) {
                stk.push(c);
            }
            else {
                if (stk.empty()) return false;
                if (stk.top() != mapping[c]) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};