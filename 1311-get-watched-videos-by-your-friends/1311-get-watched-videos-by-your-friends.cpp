class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=friends.size();
        queue<int> q;
        vector<int> dist(n,-1);
        q.push(id);
        dist[id]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:friends[u]){
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
        unordered_map<string,int> freq;
        for(int i=0;i<n;i++){
            if(dist[i]==level){
                for(string &w:watchedVideos[i])
                    freq[w]++;
            }
        }
        vector<pair<string,int>> videos;
        for(auto &[s,f]:freq){
            videos.push_back({s,f});
        }
        sort(videos.begin(),videos.end(),[&](auto a,auto b){
            if(a.second==b.second) return a.first<b.first;
            return a.second<b.second;
        });
        vector<string> ans;
        for(auto &p:videos){
            ans.push_back(p.first);
        }
        return ans;
    }
};