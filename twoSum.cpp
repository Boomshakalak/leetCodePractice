class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v(2);
        v[0] = 0;
        v[1] = numbers.size()-1;
        while (v[0]<v[1]){
            int cur = numbers[v[0]]+numbers[v[1]];
            if (cur < target) v[0]++;
            else if (cur > target) v[1]--;
            else break;
        }
        v[0]++;
        v[1]++;
        return v;
    }
};