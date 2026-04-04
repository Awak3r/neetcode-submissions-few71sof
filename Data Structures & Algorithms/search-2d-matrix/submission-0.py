class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        a1 = 0
        b1 = len(matrix) - 1
        while a1 <= b1:
            mid1 = (a1 + b1) // 2
            if target < matrix[mid1][0]:
                b1 = mid1 - 1
            elif target > matrix[mid1][-1]:
                a1 = mid1 + 1
            else:
                a2 = 0
                b2 = len(matrix[0]) - 1
                while a2 <= b2:
                    mid2 = (a2 + b2) // 2
                    if matrix[mid1][mid2] == target:
                        return True
                    elif matrix[mid1][mid2] < target:
                        a2 = mid2 + 1
                    else:
                        b2 = mid2 - 1
                return False

        return False