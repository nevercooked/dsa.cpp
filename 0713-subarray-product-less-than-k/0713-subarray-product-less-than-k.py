class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        subarrays = 0
        prod = 1
        i = 0
        for j, num in enumerate(nums):
            prod *= num
            while i <= j and prod >= k:
                prod /= nums[i] 
                i += 1
            subarrays += j - i + 1
        return subarrays