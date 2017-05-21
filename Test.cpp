#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if  (n==0) return false;
        int l = 0 ;
        int r = m-1 ;
        while (l <= r){
            cout<<"l="<<l<<" "<<"r="<<r<<endl;
            int med = l +(r-l)>>1;
            if (matrix[med][0] < target) l = med+1;
            else r = med-1;
        }
        cout<<"finally l="<<l<<" "<<endl;
        int nl = (l==0?0:(l-1));
        int sl = 0;
        int sr = n-1;
        while(sl <= sr){
            cout<<"sl="<<sl<<" "<<"sr="<<sr<<endl;
            int med1 = sl + (sr-sl)/2;
            cout<<"med1 = "<<med1<<endl;
            if (matrix[nl][med1]== target) return true;
            else if (matrix[nl][med1] < target) sl = med1+1;
            else sr = med1-1;
        }
        return false;
    }

int main(int argc, char const *argv[]){
    vector<vector<int>> r = {{1,1}};
    if (searchMatrix(r,2))cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;

}
