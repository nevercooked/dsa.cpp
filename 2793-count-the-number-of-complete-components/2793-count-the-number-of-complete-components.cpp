class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int                components = 0;
        unordered_set<int> seen;
        auto dfs = [&](this const auto& dfs, int vertex, int& vertices, int& edges) -> void {
            seen.insert(vertex);
            vertices += 1;
            edges    += graph[vertex].size();
            for (const auto& neighbor : graph[vertex]) {
                if (seen.find(neighbor) == seen.end()) {
                    dfs(neighbor, vertices, edges);
                }
            }
        };
        for (int vertex = 0; vertex < n; ++vertex) {
            if (seen.find(vertex) == seen.end()) {
                int vertices = 0;
                int edges    = 0;
                dfs(vertex, vertices, edges);
                if (vertices * (vertices - 1) == edges) {
                    components += 1;
                }
            }
        }
        return components;
    }
};