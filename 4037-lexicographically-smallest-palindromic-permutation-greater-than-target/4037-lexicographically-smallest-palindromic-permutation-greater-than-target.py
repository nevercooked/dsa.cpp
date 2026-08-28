class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        n      = len(s)
        freqs  = Counter(s)
        prefix = []
        odd_ch = ''
        for ch, freq in freqs.items():
            if (freq % 2) == 1:
                if odd_ch != '':
                    return ""
                odd_ch = ch
            freqs[ch] //= 2
        def can_creater_greater_palindrom():
            max_prefix = prefix.copy()
            for i in range(25, -1, -1):
                ch = chr(ord('a') + i)
                max_prefix.append(ch * freqs[ch])
            max_palindrome = max_prefix + [odd_ch] + max_prefix[::-1]
            return "".join(max_palindrome) > target
        for i in range(n // 2):
            if freqs[target[i]] > 0:
                freqs[target[i]] -= 1
                prefix.append(target[i])
                if can_creater_greater_palindrom():
                    continue
                freqs[target[i]] += 1
                prefix.pop()
            for j in range(ord(target[i]) - ord("a") + 1, 26):
                ch = chr(ord('a') + j)
                if freqs[ch] > 0:
                    prefix.append(ch)
                    freqs[ch] -= 1
                    for k in range(26):
                        kch = chr(ord('a') + k)
                        prefix.append(kch * freqs[kch])
                    palindrome = prefix + [odd_ch] + prefix[::-1]
                    return "".join(palindrome)
            return ""
        palindrome = prefix + [odd_ch] + prefix[::-1]
        result     = "".join(palindrome)
        return result if result > target else ""