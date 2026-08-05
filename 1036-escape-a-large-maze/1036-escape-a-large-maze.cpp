class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    unordered_set<long long> block;
    unordered_set<long long> vis;
    int limit;
    long long encode(int x,int y){
        return 1LL* x* 1000000+y;
    }
    bool dfs(vector<int>& source,vector<int>& target){
        queue<pair<int,int>> q;
        q.push({source[0],source[1]});
        vis.insert(encode(source[0], source[1]));

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            if(vis.size()>limit) return limit;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx<0 || ny<0 || nx>=1000000 || ny>=1000000) continue;
                long long key=encode(nx,ny);
                if(block.count(key) || vis.count(key)) continue;
                if(target[0]==nx && target[1]==ny)
                    return true;
                vis.insert(key);
                q.push({nx,ny});
            }
        }

        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.size()==0 || source==target) return true;
        limit=(blocked.size())*(blocked.size()-1)/2;
        for(auto &b:blocked){
            int bx=b[0];
            int by=b[1];
            block.insert(encode(bx,by));
        }
        bool st=dfs(source,target);
        vis.clear();
        bool ts=dfs(target,source);
        vis.clear();
        return st&&ts;
    }
};