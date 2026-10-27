class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> st(m,vector<char>(n,'#'));
        int i=0,j=0;
        while(j<n){
            st[0][j]='.';
            j++;
        }
        while(i<m){
            st[i][n-1]='.';
            i++;
        }
        vector<string> ans;
        for(int i=0;i<m;i++){
            string sub="";
            for(int j=0;j<n;j++){
                sub+=st[i][j];
            }
            ans.push_back(sub);
        }
        return ans;
    }
};