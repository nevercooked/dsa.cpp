class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        auto compare = [](const vector<int>& c1, const vector<int>& c2) {
            if (c1[0] == c2[0]) {
                return c1[1] > c2[1];
            }
            return c1[0] < c2[0];
        };
        sort(clips.begin(), clips.end(), compare);
        int idx   = 1;
        int start = clips[0][0];
        int end   = clips[0][1];
        int steps = 1;
        if (start > 0) {
            return -1;
        }
        while (idx < clips.size() && end < time) {
            int currStart = clips[idx][0];
            int currEnd   = clips[idx][1];
            if (currStart > end) {
                return -1;
            }
            while (idx < clips.size() && clips[idx][0] <= end) {
                currEnd = max(currEnd, clips[idx][1]);
                idx += 1;
            }
            end    = currEnd;
            steps += 1;
        }
        if (end < time) {
            return -1;
        }
        return steps;
    }
};