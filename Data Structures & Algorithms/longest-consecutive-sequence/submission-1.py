class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        nums= list(set(nums))
        nums.sort()
        print(nums)
        m_counter = 0
        counter = 1
        for i in range(1,len(nums)):
            if (nums[i] - nums[i-1]) == 1:
                counter +=1
            else:
                m_counter = max(counter, m_counter)
                counter = 1
        m_counter = max(counter, m_counter)
        return m_counter