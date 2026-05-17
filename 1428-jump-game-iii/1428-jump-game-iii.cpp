class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> fifo;
        fifo.push(start);
        visited[start] = true;
        while (!fifo.empty()) {
            int size = fifo.size();
            for (int i = 0; i < size; ++i) {
                int idx = fifo.front();
                cout << idx << endl;
                fifo.pop();
                if (arr[idx] == 0) {
                    return true;
                }
                if (idx - arr[idx] >= 0 && !visited[idx - arr[idx]]) {
                    fifo.push(idx - arr[idx]);
                    visited[idx - arr[idx]] = true;
                }
                if (idx + arr[idx] < n && !visited[idx + arr[idx]]) {
                    fifo.push(idx + arr[idx]);
                    visited[idx + arr[idx]] = true;
                }
            }
        }
        return false;
    }
};