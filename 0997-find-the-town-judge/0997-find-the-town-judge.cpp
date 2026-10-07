class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> tr(n,0);
        for(auto & t:trust){
            int a=t[0];
            int b=t[1];
            tr[a-1]--;
            tr[b-1]++;
        }

        for(int i=0;i<n;i++){
            if(tr[i]==n-1){
                return i+1;
            }
        }
        return -1;
    }
};