class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>> allOnePos1,allOnePos2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]) allOnePos1.push_back({i,j});
                if(img2[i][j]) allOnePos2.push_back({i,j});
            }
        }
        vector<vector<int>> mp(2*n,vector<int>(2*n,0));
        int ans=0;

        for(auto p1: allOnePos1){
            for(auto p2: allOnePos2){
                int dx=p2.first-p1.first+n;
                int dy=p2.second-p1.second+n;

                mp[dx][dy]++;
                ans=max(ans,mp[dx][dy]);
            }
        }
        return ans;
    }
};