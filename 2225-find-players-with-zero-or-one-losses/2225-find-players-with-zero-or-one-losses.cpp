class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<int> win,lost;
        unordered_map<int,int> lossCount;

        for(auto & match : matches){
            int w=match[0];
            int l=match[1];
            lossCount[w]+=0;
            lossCount[l]++;
        }
        for(auto &[player,cnt]: lossCount){
            if(cnt==0) win.push_back(player);
            if(cnt==1) lost.push_back(player);
        }
        sort(win.begin(),win.end());
        sort(lost.begin(),lost.end());
        return {win,lost};
    }
};