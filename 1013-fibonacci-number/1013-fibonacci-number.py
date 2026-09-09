class Solution:
    def fib(self, n: int) -> int:
        f0 = 0
        f1 = 1
        for i in range(2, n + 1):
            f2 = f1 + f0
            f0 = f1
            f1 = f2
        return f0 if n == 0 else f1