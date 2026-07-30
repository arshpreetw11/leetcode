class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int n=clips.size();
        if(clips[0][0]!=0) return -1;
        int currEnd=0;
        int far=0;
        int ans=0;
        int i=0;
        while(currEnd<time){
            while(i<n && clips[i][0]<=currEnd){
                far=max(far,clips[i][1]);
                i++;
            }
            if(far==currEnd) return -1;
            ans++;
            currEnd=far;
        }
        return ans;
    }
};