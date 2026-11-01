class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int op=0;
        unordered_map<string,int> pattern;
        for(auto &vec :matrix){
            string p="";
            int f=vec[0];
            for (int val : vec) {
                p += (val == f ? '0' : '1');
            }
            pattern[p]++;
            op=max(op,pattern[p]);
        }

        return op;
    }
};