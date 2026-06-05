class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        auto solver = [&](long long num) -> long long {
            if (num < 100) {
                return 0;
            }
            string    s = to_string(num);
            int       n = s.size();
            long long memo_cnt[16][10][10]; // As (num <= 1e15), it can have 16 digits maximum 
            long long memo_sum[16][10][10];
            memset(memo_cnt, -1, sizeof(memo_cnt));
            memset(memo_sum, -1, sizeof(memo_sum));
            auto dfs = [&](this const auto& self, int pos, int prev, int curr, bool isLimit, bool isLeading) -> pair<long long, long long> {
                if (pos == n) {
                    return {1, 0}; // Why?
                }
                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    if (memo_cnt[pos][prev][curr] != -1) {
                        return { memo_cnt[pos][prev][curr], memo_sum[pos][prev][curr]};
                    }
                }
                long long cnt = 0;
                long long sum = 0;
                int       up  = isLimit ? s[pos] - '0' : 9;
                for (int digit = 0; digit <= up; ++digit) {
                    bool newLeading = isLeading && (digit == 0);
                    int  newPrev    = curr;
                    int  newCurr    = newLeading ? -1 : digit;
                    auto [subCnt, subSum] = self(pos + 1, newPrev, newCurr, isLimit && (digit == up), newLeading); 
                    if (!newLeading && prev >= 0 && curr >= 0) {
                        if ((prev < curr && curr > digit) || (prev > curr && curr < digit)) {
                            sum += subCnt;
                        }
                    }
                    cnt += subCnt;
                    sum += subSum;
                }
                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    memo_cnt[pos][prev][curr] = cnt;
                    memo_sum[pos][prev][curr] = sum;
                }

                return {cnt, sum};
            };
            auto [_, sum] = dfs(0, -1, -1, true, true);
            return sum;
        };
        return solver(num2) - solver(num1 - 1);
    }
};