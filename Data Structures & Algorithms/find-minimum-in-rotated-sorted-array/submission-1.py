class Solution:
    def findMin(self, nums: List[int]) -> int:
        a = 0
        b = len(nums) - 1
        min_c = 10**10
        while a <= b:
            mid = (a + b) // 2
            if nums[mid] < nums[b]:
                b = mid
            else:
                a = mid + 1
            min_c = min(min_c, nums[mid])
        return min_c