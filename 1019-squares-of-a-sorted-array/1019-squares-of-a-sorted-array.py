class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        squares = []
        i = 0
        j = len(nums) - 1
        while i <= j:
            if abs(nums[i]) > abs(nums[j]):
                squares.append(nums[i] * nums[i])
                i += 1
            else:
                squares.append(nums[j] * nums[j])
                j -= 1
        squares.reverse()
        return squares