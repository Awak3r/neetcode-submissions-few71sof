class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        suma = 1
        flag = 0
        for i in range(len(nums)):
            if nums[i]!= 0:
                suma*= nums[i]
            else:
                flag+=1
        res = []
        for i in range(len(nums)):
            if flag < 2:
                if nums[i] != 0 and flag == 1:
                    res.append(0)
                elif nums[i] == 0 and flag == 1:
                    res.append(suma)
                else:
                    res.append(suma//nums[i])
            else:
                res.append(0)

        return res