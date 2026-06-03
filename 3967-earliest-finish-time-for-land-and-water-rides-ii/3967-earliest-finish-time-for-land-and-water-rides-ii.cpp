class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int time = numeric_limits<int>::max();
        int n    = landStartTime.size();
        int m    = waterStartTime.size();

        auto solve = [](const vector<int>& s1, const vector<int>& l1, const vector<int>& s2, const vector<int>& l2) -> int {
            int f1 = numeric_limits<int>::max();
            for (int i = 0; i < s1.size(); ++i) {
                f1 = min(f1, s1[i] + l1[i]);
            }
            int f2 = numeric_limits<int>::max();
            for (int i = 0; i < s2.size(); ++i) {
                f2 = min(f2, max(f1, s2[i]) + l2[i]);
            }
            return f2;
        };
        int land_water = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);
    }
};