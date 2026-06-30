class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long sum=0;
                int cnt=0;
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        if(i+k>=0 && i+k<n && j+l>=0 && j+l<m){
                            cnt++;
                            sum+=img[i+k][j+l];
                        }
                    }
                }
                sum/=cnt;
                ans[i][j]=sum;
            }
        }
        return ans;
    }
};