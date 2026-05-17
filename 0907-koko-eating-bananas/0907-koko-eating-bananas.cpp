class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l     = 1;
        int r     = *max_element(piles.begin(), piles.end());
        auto work = [&](const int& speed) -> bool {
            int time = 0;
            for (const auto& pile : piles) {
                time += ((pile / speed) + (pile % speed > 0 ? 1 : 0));
                if (time > h) {
                    return false;
                }
            }
            return true;
        };
        while (l < r) {
            int m = l + ((r - l) / 2);
            if (work(m)) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return r;
    }
};