class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int                             n    = source.size();
        int                             dist = n;
        vector<bool>                    visited(n, false);
        unordered_map<int, vector<int>> graph;
        for (const auto& swap : allowedSwaps) {
            int u = swap[0];
            int v = swap[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 0; i < n; ++i) {
            if (graph.find(i) == graph.end()) {
                visited[i] = true;
                if (source[i] == target[i]) {
                    dist -= 1;
                }
                continue;
            }
            if (visited[i]) {
                continue;
            }
            unordered_map<int, int> freqsSource;
            unordered_map<int, int> freqsDest;
            queue<int>              fifo;
            fifo.push(i);
            visited[i] = true;
            while (!fifo.empty()) {
                int size = fifo.size();
                for (int j = 0; j < size; ++j) {
                    int vertex = fifo.front();
                    fifo.pop();
                    freqsSource[source[vertex]] += 1;
                    freqsDest[target[vertex]]   += 1;
                    for (const auto& neighbor : graph[vertex]) {
                        if (!visited[neighbor]) {
                            fifo.push(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }
            }
            for (const auto& [e, freq] : freqsSource) {
                if (freqsDest.find(e) != freqsDest.end()) {
                    dist -= min(freq, freqsDest[e]);
                }
            }
        }
        return dist;
    }
};