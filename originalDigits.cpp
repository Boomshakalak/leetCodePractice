class Solution {
    vector<string> digits = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int count[26] = {0};
    int digit[10] = {0};
public:
    string originalDigits(string s) {
        string res;
        for (auto x : s)count[x-'a']++;
        digit[0] = remove(0,'z');
        digit[6] = remove(6,'x');
        digit[8] = remove(8,'g');
        digit[2] = remove(2,'w');
        digit[3] = remove(3,'h');
        digit[4] = remove(4,'r');
        digit[5] = remove(5,'f');
        digit[9] = remove(9,'i');
        digit[7] = remove(7,'s');
        digit[1] = remove(1,'o');
        for (int i = 0 ; i < 10; i++){
            if (digit[i]) res += string(digit[i],i+'0');

        }
        return res;
    }
    int remove(int digit,char c){
        int tmp = count[c-'a'];
        for (char ch : digits[digit]) count[ch-'a'] -= tmp;
        return tmp;
    }
};
