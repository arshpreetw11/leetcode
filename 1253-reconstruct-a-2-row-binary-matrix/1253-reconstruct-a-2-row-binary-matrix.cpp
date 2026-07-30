class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int row=2;
        int col=colsum.size();
        //sum can be 0/1/2;
        //if sum==0 then col={0,0} ; if sum==2 then col={1,1} ; if sum==1 then col {0,1} / {1,0};
        vector<vector<int>> res(2,vector<int>(col,0));
        for(int i=0;i<col;i++){
            if(colsum[i]==0){
                continue;
            }
            else if(colsum[i]==2){
                res[0][i]=1;
                res[1][i]=1;
                upper--;
                lower--;
            }
            if(upper<0 || lower<0) return {};
            else if(colsum[i]==1){
                if(upper>lower){
                    res[0][i]=1;
                    upper--;
                }else{
                    res[1][i]=1;
                    lower--;
                }
            }
        }
        if(upper!=0 || lower!=0) return {};
        return res;
    }
};