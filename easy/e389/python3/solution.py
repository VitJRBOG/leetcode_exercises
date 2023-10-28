class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        if len(t) == 1:
            return t

        sorted_s = list(s)

        for i in range(len(sorted_s)):
            tmp = sorted_s[i]
            j = i
            while 0 < j and tmp < sorted_s[j-1]:
                sorted_s[j] = sorted_s[j-1]
                j -= 1
            sorted_s[j] = tmp

        sorted_t = list(t)

        for i in range(len(sorted_t)):
            tmp = sorted_t[i]
            j = i
            while 0 < j and tmp < sorted_t[j-1]:
                sorted_t[j] = sorted_t[j-1]
                j -= 1
            sorted_t[j] = tmp

        i = 0

        while i < len(sorted_s):
            if sorted_s[i] != sorted_t[i]:
                return sorted_t[i]

            i += 1

        return sorted_t[-1]
