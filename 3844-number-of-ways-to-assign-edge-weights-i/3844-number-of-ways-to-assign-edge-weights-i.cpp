class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        auto dfs = [&](this const auto& self, int node, int parent) -> int {
            int max_depth = 0;
            for (const auto& neighbor : graph[node]) {
                if (neighbor == parent) {
                    continue;
                }
                max_depth = max(max_depth, 1 + self(neighbor, node));
            }
            return max_depth;
        };
        auto binaryexp = [&](int x, int exp) -> int {
            int mod = 1e9 + 7;
            int res = 1;
            x %= mod;
            while (exp) {
                if (exp & 1) {
                    res = (static_cast<long long>(res) * x) % mod;
                }
                exp >>= 1;
                x     = (static_cast<long long>(x) * x) % mod;
            }
            return res;
        };
        int max_depth = dfs(1, -1);
        cout << max_depth << endl;
        return max_depth <= 0 ? 0 : binaryexp(2, max_depth - 1);
    }
};