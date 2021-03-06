class NumArray {
public:
    NumArray(vector<int> nums) {
        int tmp = 0;
        sum.push_back(tmp);
        for (auto x : nums){
            tmp += x;
            sum.push_back(tmp);
        }
    }

    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
