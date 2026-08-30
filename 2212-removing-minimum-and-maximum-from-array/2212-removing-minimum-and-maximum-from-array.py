class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 1
        imin = 0
        imax = 0
        for i, num in enumerate(nums):
            if num < nums[imin]:
                imin = i
            if num > nums[imax]:
                imax = i
        return min(
            min(
                max(imin, imax) + 1,
                len(nums) - min(imin, imax)
            ),
            (min(imin, imax) + 1) + (len(nums) - max(imin, imax))
        )