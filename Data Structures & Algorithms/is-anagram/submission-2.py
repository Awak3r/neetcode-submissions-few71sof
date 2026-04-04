class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        for i in range(len(s)):
            if s.count(s[i]) != t.count(s[i]):
                return False

        for i in range(len(t)):
            if s.count(t[i]) != t.count(t[i]):
                return False

        return True
