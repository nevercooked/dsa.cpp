class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        if s.count('1') < k:
            return ""
        shortest = s
        ones = 0
        i = 0
        for j, ch in enumerate(s):
            ones += int(ch)
            while i <= j and (ones > k or s[i] == '0'):
                ones -= int(s[i])
                i += 1
            if ones == k:
                ss = s[i:j + 1]
                if len(ss) < len(shortest) or (len(ss) == len(shortest) and ss < shortest):
                    shortest = ss
        return shortest
            