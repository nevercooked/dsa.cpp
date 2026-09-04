class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        m1 = nums[0]
        for i, num in enumerate(nums):
            m1 = max(m1, num)
            m2 = min(nums[i:])
            if m1 - m2 <= k:
                return i
        return -1