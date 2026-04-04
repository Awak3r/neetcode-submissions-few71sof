class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for k in range(len(nums)):
            i = k + 1
            j = len(nums) - 1
            while i < j:
                if nums[i] + nums[k] + nums[j] == 0:
                    r = [nums[k], nums[i], nums[j]]
                    if r not in res:
                        res.append(r)
                    i += 1
                    j -= 1
                elif nums[i] + nums[k] + nums[j] > 0:
                    j-=1
                else:
                    i += 1
        return res
