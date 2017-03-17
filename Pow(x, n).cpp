class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        int flag = 1;
        if (x==0) return 0;
        else if (x==1) return 1;
        else if (x==-1){
            if (n %2 ==1) return -1;
            else return 1;
        }
        else
        {
            if (n<0) {
            flag= 0;
            n = abs(n);
        }
                while (n--){
                res *= x;
                if ((abs(res) <0.00000001) ||abs(1/res)<0.00000001) return 0;
            }
        }

            return flag?res:1/res;
    }
};