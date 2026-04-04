#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Множества для строк, столбцов и блоков 3x3
        vector<unordered_set<char>> hor(9);  
        vector<unordered_set<char>> ver(9);  
        vector<unordered_set<char>> d9(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num != '.') {
                    if (hor[i].find(num) != hor[i].end()) {
                        return false;
                    }
                    hor[i].insert(num);
                    if (ver[j].find(num) != ver[j].end()) {
                        return false;
                    }
                    ver[j].insert(num);
                    int ind = (i / 3) * 3 + (j / 3);
                    if (d9[ind].find(num) != d9[ind].end()) {
                        return false;
                    }
                    d9[ind].insert(num);
                }
            }
        }
        return true;
    }
};