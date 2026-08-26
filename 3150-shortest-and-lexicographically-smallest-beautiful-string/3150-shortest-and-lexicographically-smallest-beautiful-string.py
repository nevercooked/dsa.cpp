class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        if s.count('1') < k:
            return ""
        shortest = s
        ones = 0
        i = 0
        for j, ch in enumerate(s):
            if ch == '1':
                ones += 1
            while i <= j and (ones > k or s[i] == '0'):
                if s[i] == '1':
                    ones -= 1
                i += 1
            if ones == k:
                t = s[i:j + 1]
                if len(t) < len(shortest) or (len(t) == len(shortest) and t < shortest):
                    shortest = t
        return shortest
            