class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        prefixSum = [0]
        for num in nums:
            prefixSum.append(prefixSum[-1] + num)
        cpt = 0
        for i in range(1, len(nums)):
            left  = prefixSum[i]
            right = prefixSum[-1] - left
            if left >= right:
                cpt += 1
        return cpt