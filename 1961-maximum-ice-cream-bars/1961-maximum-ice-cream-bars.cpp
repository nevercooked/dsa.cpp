class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cpt = 0;
        for (int i = 0; i < costs.size() && coins >= costs[i]; ++i) {
            cpt   += 1;
            coins -= costs[i];
        }
        return cpt;
    }
};