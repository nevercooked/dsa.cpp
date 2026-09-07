class Solution:
    def distinctSubseqII(self, s: str) -> int:
        dp   = [1]
        seen = {}
        mod  = 10**9 + 7
        for idx, ch in enumerate(s):
            dp.append(2 * dp[-1])
            if ch in seen:
                dp[-1] -= dp[seen[ch]]
            seen[ch] = idx
        return (dp[-1] - 1) % mod