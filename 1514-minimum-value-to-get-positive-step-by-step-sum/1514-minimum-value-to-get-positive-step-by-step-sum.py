class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        running    = 0
        minRunning = +inf
        for num in nums:
            running += num
            minRunning = min(minRunning, running)
        return 1 if minRunning >= 0 else abs(minRunning) + 1