class Solution:
    def search(self, nums: List[int], target: int) -> int:
        a = 0
        b = len(nums) - 1

        while a <= b:
            mid = (a + b) // 2

            if nums[mid] == target:
                return mid

            if nums[a] <= nums[mid]:
                if nums[a] <= target < nums[mid]:
                    b = mid - 1
                else:
                    a = mid + 1
            else:
                if nums[mid] < target <= nums[b]:
                    a = mid + 1
                else:
                    b = mid - 1

        return -1