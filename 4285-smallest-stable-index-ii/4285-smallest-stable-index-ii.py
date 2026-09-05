class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        m1     = nums[0]
        m2     = [0] * len(nums)
        m2[-1] = nums[-1]
        for i in range(len(nums) - 2, -1, -1):
            m2[i] = min(nums[i], m2[i + 1])
        for i, num in enumerate(nums):
            m1 = max(m1, num)
            if m1 - m2[i] <= k:
                return i
        return -1