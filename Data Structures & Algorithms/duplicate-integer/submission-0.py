class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        r = []
        for i in range(len(nums)):
            if nums[i] not in r:
                r.append(nums[i])  
            else:
                return True
        return False