class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        mmm = max(piles)
        a = 1
        b = mmm
        res = []
        while a<=b:
            cur = 0
            mid = (a + b) // 2
            for i in range(len(piles)):
                rr = piles[i]//mid + (piles[i]%mid != 0) * 1
                if rr != 0:
                    cur += rr
                else:
                    cur += 1
            print(cur, mid)
            if cur <= h:
                b = mid - 1
                res.append(mid)
            if cur > h:
                a = mid + 1
        print(res)
        return min(res)