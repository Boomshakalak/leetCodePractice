class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() <= 1) return ratings.size();
    int left=0, right=0, pos=0, n=ratings.size(), sum=0;
    while(left < n) {
    	int i, lval = 1, rval;
    	if(left!=0 && ratings[left]>ratings[left-1]) lval++;
    	for(i = left+1; i<n && ratings[i]>ratings[i-1]; i++) {// gradient increase
    		sum += lval;
    		if (ratings[i] > ratings[i-1]) lval++;
    	}
    	pos = --i; // find local max
    	for(right = i+1; right<n && ratings[right]<ratings[right-1]; right++); // gradient decrease
    	right--; // right point to the last local decrease element
    	for(i = right, rval = 1; i > pos; i--) {
    		sum += rval;
    		if (ratings[i] < ratings[i-1]) {
    			rval++;
    		}
    	}
        sum += max(lval, rval);
    	left = right+1;
    }
    return sum;
    }
};
