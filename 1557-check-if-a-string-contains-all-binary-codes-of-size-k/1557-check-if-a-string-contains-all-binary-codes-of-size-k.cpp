class Solution {
public:
    bool hasAllCodes(string s, int k) {
        std::unordered_set<std::string> codes;
        for (int i = 0; i < static_cast<int>(s.size()) - k + 1; ++i) {
            std::string code = s.substr(i, k);
            codes.insert(code);
        }
        return codes.size() == std::pow(2, k);
    }
};