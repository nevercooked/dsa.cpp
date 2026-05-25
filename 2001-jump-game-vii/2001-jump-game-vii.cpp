class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int          n  = s.size();
        int          jj = 1;
        vector<bool> visited(n, false);
        queue<int>   fifo;
        fifo.push(0);
        visited[0] = true;
        while (!fifo.empty()) {
            int size = fifo.size();
            for (int i = 0; i < size; ++i) {
                int j = fifo.front();
                fifo.pop();
                if (j == (n - 1)) {
                    return true;
                }
                for (int k = max(jj, j + minJump); k <= min(j + maxJump, n - 1); ++k) {
                    if (s[k] == '0' && !visited[k]) {
                        if (k == (n - 1)) {
                            return true;
                        }
                        fifo.push(k);
                        visited[k] = true;
                    }
                }
                jj = i + maxJump + 1;
            }
        }
        return false;
    }
};