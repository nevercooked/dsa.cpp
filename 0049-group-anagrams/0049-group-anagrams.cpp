class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (const auto& s : strs) {
            std::string ss = s;
            std::sort(ss.begin(), ss.end());
            groups[ss].push_back(s);
        }
        std::vector<std::vector<std::string>> groupedAnagrams; 
        for (auto& [_, group] : groups) {
            groupedAnagrams.push_back(std::move(group));
        }
        return groupedAnagrams;
    }
};