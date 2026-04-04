class Solution:
    def isPalindrome(self, s_n: str) -> bool:
        s = []
        for i in range(len(s_n)):
            if (s_n[i]>='a' and s_n[i] <='z') or (s_n[i]>='A' and s_n[i] <='Z') or (s_n[i]>='0' and s_n[i] <='9'):
                s.append(s_n[i].lower())
        l = 0
        r = len(s) - 1 
        while l<r:
            if s[l] != s[r]:
                return False
            r-=1
            l+=1
        return True