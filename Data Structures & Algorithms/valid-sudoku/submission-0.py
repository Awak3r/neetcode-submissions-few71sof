class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = 9
        print(board)
        for i in range(n):
            m = []
            for j in range(n):
                if board[i][j] in m:
                     return False
                elif board[i][j] != '.':
                    m.append(board[i][j])
        for i in range(n):
            m = []
            for j in range(n):
                if board[j][i] in m:
                     return False
                elif board[j][i] != '.':
                    m.append(board[j][i])
        m = [[[] for i in range(n//3)] for j in range(n//3)]
        for i in range(n):
            for j in range(n):
                if board[i][j] in m[i//3][j//3]:
                     return False
                elif board[i][j] != '.':
                    m[i//3][j//3].append(board[i][j])
        return True