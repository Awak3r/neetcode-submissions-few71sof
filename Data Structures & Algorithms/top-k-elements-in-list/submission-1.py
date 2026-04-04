class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        S = {}
        for i in range(len(nums)):
            S[nums[i]] = S.get(nums[i], 0) + 1
        S_s = dict(sorted(S.items(), key=lambda x: x[1], reverse = True))
        print(S_s)
        res = []
        m = 0
        for i in S_s.keys():
            res.append(i)
            m+=1
            if k == m:
                break  
        return res