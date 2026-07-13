class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        vis[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int room=q.front();
            q.pop();
            vis[room]=true;
            for(int r: rooms[room]){
                if(!vis[r]){
                    q.push(r);
                }
            }
        }
        for(bool unlocked: vis){
            if(!unlocked) return false;
        }
        return true;
    }
};