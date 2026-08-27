class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> freq;
        for(int t:tasks){
            freq[t]++;
        }
        int op=0;
        for(int x:tasks){
            if(freq[x]==1) return -1;
            if(freq[x]==0) continue;
            //if(freq[x]==4) freq[x]-=2;
            if(freq[x]%3==0){
                freq[x]-=3;
            }else{
                freq[x]-=2;
            }
            op++;
        }
        return op;
    }
};