class Solution {
public:
    string processStr(string s) {
        string ps;
        for (const auto& c : s) {
            switch (c) {
                case '*':
                    if (!ps.empty()) {
                        ps.pop_back();
                    }
                    break;
                case '#':
                    ps.append(ps);
                    break;                   
                case '%':
                    reverse(ps.begin(), ps.end());
                    break;                   
                default:
                    ps.push_back(c);
            }
        }
        return ps;
    }
};