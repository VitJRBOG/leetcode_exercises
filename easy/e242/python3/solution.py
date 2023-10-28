class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        char_counter = {}

        for c in s:
            if c not in char_counter:
                char_counter[c] = 1
            else:
                char_counter[c] += 1

        for c in t:
            if c not in char_counter:
                return False
            else:
                char_counter[c] -= 1
                if char_counter[c] == 0:
                    del (char_counter[c])

        if len(char_counter) == 0:
            return True

        return False
