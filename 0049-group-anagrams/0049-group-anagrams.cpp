class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> m;
        for (const auto& s : strs) {
            std::string ss = s;
            std::sort(ss.begin(), ss.end());
            m[ss].push_back(s);
        }
        std::vector<std::vector<std::string>> anagrams;
        for (const auto& [_, vec] : m)
            anagrams.push_back(vec);
        return anagrams;
    }
};