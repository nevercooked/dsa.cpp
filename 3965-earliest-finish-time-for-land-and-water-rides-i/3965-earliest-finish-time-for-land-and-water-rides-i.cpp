class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int time = numeric_limits<int>::max();
        for (int i = 0; i < landStartTime.size(); ++i) {
            int land = landStartTime[i] + landDuration[i];
            for (int j = 0; j < waterStartTime.size(); ++j) {
                int land_water = max(land, waterStartTime[j]) + waterDuration[j];
                int water      = waterStartTime[j] + waterDuration[j];
                int water_land = max(water, landStartTime[i]) + landDuration[i];
                time = min(time, min(land_water, water_land));
            }
        }
        return time;
    }
};