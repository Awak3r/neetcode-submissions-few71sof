class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = 9
        m = [[[] for i in range(n//3)] for j in range(n//3)]
        for i in range(n):
            m1 = []
            m2 = []
            for j in range(n):
                if board[i][j] in m1:
                     return False
                elif board[i][j] != '.':
                    m1.append(board[i][j])
                if board[j][i] in m2:
                     return False
                elif board[j][i] != '.':
                    m2.append(board[j][i])
                if board[i][j] in m[i//3][j//3]:
                     return False
                elif board[i][j] != '.':
                    m[i//3][j//3].append(board[i][j])
        return True