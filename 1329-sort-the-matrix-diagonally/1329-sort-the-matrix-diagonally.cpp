class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int col=0;col<n;col++){
            int i=0;
            int j=col;
            vector<int> st;
            while(i<m && j<n){
                st.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(st.begin(),st.end());
            i=0;
            j=col;
            int x=0;
            while(i<m && j<n){
                mat[i][j]=st[x];
                x++;
                i++;
                j++;
            }

        }
        for(int row=1;row<m;row++){
            int i=row;
            int j=0;
            vector<int> st;
            while(i<m && j<n){
                st.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(st.begin(),st.end());
            i=row;
            j=0;
            int x=0;
            while(i<m && j<n){
                mat[i][j]=st[x];
                x++;
                i++;
                j++;
            }
            
        }
        return mat;
    }
};