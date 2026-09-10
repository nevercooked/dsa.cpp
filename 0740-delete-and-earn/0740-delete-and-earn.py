class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        n     = len(nums)
        freqs = [0] * (max(nums) + 1)
        for num in nums:
            freqs[num] += num
        dp    = [0] * len(freqs)
        dp[1] = freqs[1] 
        for i in range(2, len(freqs)):
            dp[i] = max(
                freqs[i] + dp[i - 2],
                dp[i - 1]
            )
        return dp[-1]