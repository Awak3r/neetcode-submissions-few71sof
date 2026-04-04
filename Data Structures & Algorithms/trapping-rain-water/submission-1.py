class Solution:
    def trap(self, heights: List[int]) -> int:
        l = 0
        r = len(heights) - 1
        max_l = heights[l]
        max_r = heights[r]
        res = 0
        while l < r:
            if max_l < max_r:
                l+=1
                max_l = max(max_l, heights[l])
                res+=max_l - heights[l]
            else:
                r-=1
                max_r = max(max_r, heights[r])
                res+=max_r - heights[r]
        
        return res

