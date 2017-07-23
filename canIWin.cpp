class Solution {
 public:
 	bool canIWin(int maxChoosableInteger, int desiredTotal) {
 		if(desiredTotal == 0) return true;

 		if((maxChoosableInteger+1) * maxChoosableInteger / 2 < desiredTotal)
 			return false;

 		unordered_map<int, bool> dp;

 		// a bit in record being equal to 1 means a number is available
 		// for example if record is ..1000, it means number 3 has not been used,
 		// for convenience we do not use the least significant digit.
 		int record = (0xffffffff >> (31-maxChoosableInteger));
 		return f(desiredTotal, record, dp);
 	}

 	bool f(int dt, int record, unordered_map<int, bool> &dp)
 	{
 		if(dp.count(record)) {
 			return dp[record];
 		}

 		// we know maxChoosableInteger wont be larger than 20
 		for(int i = 20; i > 0; i--) {
 			int bit = 1 << i;

 			// if this number has not been used
 			if(record & bit) {
 				if(i >= dt) {
 					return true;
 				}
 				// mark number i so it has been used and check whether the opponent
 				// can win. Notice that due to the annoyance of [] operator
 				// automatically inserting value into a set in c++, we should not
 				// use dp[...] = f(..., dp) to avoid changing dp BEFORE the
 				// function is called.
 				bool t = f(dt-i, record^bit, dp);
 				dp[record^bit] = t;
 				if(t == false) {
 					return true;
 				}
 			}
 		}
 		return false;

 	}

 };
