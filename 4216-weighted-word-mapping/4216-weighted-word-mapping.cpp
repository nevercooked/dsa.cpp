class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        stringstream ss;
        for (const auto& w : words) {
            int sum = 0;
            for (const auto& c : w) {
                sum = (sum + weights[c - 'a']) % 26;
            }
            ss.put('z' - sum);
        }
        return ss.str();
    }
};