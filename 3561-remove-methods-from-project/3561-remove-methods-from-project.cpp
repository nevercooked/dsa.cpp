class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n);
        vector<int>         in(n, 0);
        bitset<100005>      sus;
        for (const auto& invocation : invocations) {
            edges[invocation[0]].push_back(invocation[1]);
            in[invocation[1]] += 1;
        }
        queue<int> q;
        q.push(k);
        sus.set(k);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                in[v] -= 1;
                if (!sus.test(v)) {
                    q.push(v);
                    sus.set(v);
                }
            }
        }
        bool removeAll = true;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (sus.test(i) && in[i] > 0) {
                removeAll = false;
                break;
            }
            if (!sus.test(i)) {
                res.push_back(i);
            }
        }
        if (!removeAll) {
            vector<int> nodes(n);
            iota(nodes.begin(), nodes.end(), 0);
            return nodes;
        }
        return res;
    }
};