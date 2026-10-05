class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int i=0,j=0;
        bool up=true;
        vector<int> res;
        while(i<m && j<n){
            if(up){
                while(i>=0 && i<m && j>=0 && j<n){
                    res.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                if(j==n){
                    i+=2;
                    j--;
                }else
                    i++;
                up=!up;
            }else{
                while(i>=0 && i<m && j>=0 && j<n){
                    res.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                if(i==m){
                    j+=2;
                    i--;
                }else
                    j++;
                up=!up;
            }
        }
        return res;
    }
};