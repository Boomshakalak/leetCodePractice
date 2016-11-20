//It seems the question disappear in some what reason so I cannot figure out whether it is right or not
//Just have fun I think the logic is with no question!


class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        	if (start == end) return 0;
        	queue<string> qs;
        	string st;
        	unordered_map<string,int> um;
        	um[start]=0;
        	qs.push(start);
        	while (!qs.empty()){
        		st = qs.pop();
        		for (int i = 0; i < bank.size(); ++i)
        		{
        			if (um.find(st) == um.end() && isValidMutation(st,bank[i])){
        				um[bank[i]] = um[st]+1;
        				if (bank[i] == end) return um[end];
        				qs.push_back(bank[i]);
        			}
        		}
        	}
        	return -1;
    }
    bool isValidMutation(string& a, string& b){
    	if (a.size() != b.size()) return false;
    	int cnt = 0;
    	for (int i = 0; i < a.size(); ++i)
    	{
    		if (a[i]!=b[i]) cnt++;
    	}
    	if (1 == cnt ) return true;
    	return false;
    }
};