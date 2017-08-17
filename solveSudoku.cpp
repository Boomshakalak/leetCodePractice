class Solution {
    short col[9] = {0},row[9] = {0},blo[9] = {0};
public:
bool solveSudoku(vector<vector<char>>& b, int i, int j) {
       if (i == 9) return true;
       if (j == 9) return solveSudoku(b, i+1, 0);
       if (b[i][j] == '.') {
         for (int ch = 1; ch <= 9; ch++) {
           if (!(col[j] & 1 << ch) && !(row[i] & 1 << ch) && !(blo[i / 3 * 3 + j / 3] & 1 << ch)) {
                b[i][j] = ch + '0';
                col[j] |= 1 << ch;
                row[i] |= 1 << ch;
                blo[i / 3 * 3 + j / 3] |= 1 << ch;
                if (solveSudoku(b, i, j+1)) return true;
                b[i][j] = '.';
                col[j] ^= 1 << ch;
                row[i] ^= 1 << ch;
                blo[i / 3 * 3 + j / 3] ^= 1 << ch;
            }
        }
        return false;
    } else
          return solveSudoku(b, i, j+1);
}
void solveSudoku(vector<vector<char>>& b) {
     for (int i=0;i<9;i++)
        for (int j=0;j<9;j++) {
            if (b[i][j] != '.') {
                col[j] |= 1 << b[i][j]-'0';
                row[i] |= 1 << b[i][j]-'0';
                blo[i / 3 * 3 + j / 3] |= 1 << b[i][j]-'0';
            }
    }
    solveSudoku(b, 0, 0);
    return;
}
};
