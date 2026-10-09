class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> P(m);
        for(int i=0;i<m;i++){
            P[i]=i;
        }
        vector<int> ans;
        for(int q:queries){
            int val=P[q-1];
            ans.push_back(val);
            P[q-1]=0;
            for(int i=0;i<m;i++){
                if(i==q-1) continue;
                if(val>P[i]) P[i]++;
            }
        }
        return ans;
    }
};