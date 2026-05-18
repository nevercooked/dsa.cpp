class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> graph;
        int                             jumps = 0;
        for (int i = 0; i < arr.size(); ++i) {
            graph[arr[i]].push_back(i);
        }
        queue<int>   fifo;
        vector<bool> visited(arr.size(), false);
        fifo.push(0);
        visited[0] = true;
        while (!fifo.empty()) {
            int size = fifo.size();
            for (int i = 0; i < size; ++i) {
                int idx = fifo.front();
                fifo.pop();
                if (idx == arr.size() - 1) {
                    return jumps;
                }
                if (idx + 1 < arr.size() && !visited[idx + 1]) {
                    fifo.push(idx + 1);
                    visited[idx + 1] = true;
                }
                if (idx - 1 > 0 && !visited[idx - 1]) {
                    fifo.push(idx - 1);
                    visited[idx - 1] = true;
                }
                for (const auto& nextIdx : graph[arr[idx]]) {
                    if (nextIdx != idx && !visited[nextIdx]) {
                        fifo.push(nextIdx);
                        visited[nextIdx] = true;
                    }
                }
                graph.erase(arr[idx]);
            }
            if (!fifo.empty()) {
                jumps += 1;
            }
        }
        return jumps;
    }
};
