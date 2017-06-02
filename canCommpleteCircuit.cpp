class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> rem(gas.size());
        for (int i = 0 ; i < gas.size(); ++i){
            rem[i] = gas[i]-cost[i];
        }
        int tmp_index = 0 ;
        int tmp_sum = 0 ;
        int max_sum = 0;
        int max_index = 0;
        for (int i = 0 ; i < 2*gas.size(); ++i ){
            if (tmp_sum == 0) tmp_index = i%gas.size();
            tmp_sum += rem[i%gas.size()];
            if(tmp_sum >= max_sum){
                max_sum = tmp_sum;
                max_index = tmp_index;
            }
            if (tmp_sum < 0 ){
                tmp_sum = 0;
            }
        }
        int curgas=0;
        for (int i = 0 ; i < gas.size();++i){
            curgas = curgas+rem[(i+max_index)%gas.size()];
            if (curgas < 0) return -1;
        }
        return max_index;
    }
};


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total(0), subsum(INT_MAX), start(0);
        for(int i = 0; i < n; ++i){
            total += gas[i] - cost[i];
            if(total < subsum) {
                subsum = total;
                start = i + 1;
            }
        }
        return (total < 0) ?  -1 : (start%n);
    }
};
