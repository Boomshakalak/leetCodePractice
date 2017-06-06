//This is a classical method computing the sum of 2 integers

class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a:getSum(a^b, (a&b) <<1);
    }
};
