class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        int mxDiff=0;
        for(int i=1;i<points.size();i++){
            int diff=points[i][0]-points[i-1][0];
            mxDiff=max(mxDiff,diff);
        }
        return mxDiff;
    }
};