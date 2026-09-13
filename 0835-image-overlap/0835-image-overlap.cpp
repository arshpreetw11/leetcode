class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>> allOnePos1,allOnePos2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]) allOnePos1.push_back({i,j});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img2[i][j]) allOnePos2.push_back({i,j});
            }
        }
        map<pair<int,int>,int> mp;
        for(auto p1: allOnePos1){
            for(auto p2: allOnePos2){
                int dx=p2.first-p1.first;
                int dy=p2.second-p1.second;

                mp[{dx,dy}]++;
            }
        }
        int ans=0;
        for(auto &x: mp){
            ans=max(ans,x.second);
        }
        return ans;
    }
};