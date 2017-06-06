/* leetcode test code */
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        res = matrix;
        for (int i = 0 ; i < m; i++){
            int tmp = 0;
            for (int j = 0 ; j < n; j++){
                tmp += matrix[i][j];
                res[i][j] = (i==0?0:res[i-1][j])+tmp;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return res[row2][col2]-(row1==0?0:res[row1-1][col2])-(col1==0?0:res[row2][col1-1])+((row1==0 || row2==0)?0:res[row1-1][row2-1]);

    }
    void printres(){
        for (auto x:res){
            for (auto t : x)cout<<t<<" ** ";
            cout<<endl;
        }
    }
private:
    vector<vector<int>> res;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    NumMatrix p = NumMatrix(matrix);
    p.printres();
    cout<<p.sumRegion(2,1,4,3)<<endl;
    return 0;
}
