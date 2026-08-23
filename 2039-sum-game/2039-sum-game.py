class Solution:
    def sumGame(self, num: str) -> bool:
        sumLeft    = 0
        sumRight   = 0
        spotsLeft  = 0
        spotsRight = 0
        n          = len(num)
        mid        = n // 2
        for i in range(0, mid):
            if num[i] == '?':
                spotsLeft += 1
            else:
                sumLeft += int(num[i])
        for i in range(mid, n):
            if num[i] == '?':
                spotsRight += 1
            else:
                sumRight += int(num[i])
        spots = spotsLeft + spotsRight
        return (spots % 2) == 1 or (sumLeft - sumRight) != (((spotsRight - spotsLeft) * 9) // 2)