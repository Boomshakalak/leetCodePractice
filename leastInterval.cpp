class Solution {
public:
    bool static cmp(int a,int b){return a > b;}
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0;
        int task[26]={0};
        for (auto x:tasks)task[x-'A']++;
        sort(task,task+26,cmp);
        while(task[0]>0){
            int count = 0;
            for (int i = 0 ; i < 26;i++){
                if (task[i]) {count++;
                task[i]--;}
                if (count == n+1) break;
            }
            sort(task,task+26,cmp);
            if (task[0]) res += n+1;
            else res += count;
        }
        return res;
    }
};
