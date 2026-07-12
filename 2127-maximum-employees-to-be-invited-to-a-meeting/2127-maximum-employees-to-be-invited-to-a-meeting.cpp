class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<int> indeg(n,0), chain(n,0);
        vector<bool> vis(n,false);
        for(int fav:favorite){
            indeg[fav]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=true;
            int nxt=favorite[node];
            chain[nxt]=chain[node]+1;
            if(--indeg[nxt]==0)
                q.push(nxt);
        }
        int maxcycle=0,total=0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int current = i, cycleLength = 0;
                while (!vis[current]) {
                    vis[current] = true;
                    current = favorite[current];
                    cycleLength++;
                }

                if (cycleLength == 2) {
                    total += 2 + chain[i] + chain[favorite[i]];
                } else {
                    maxcycle = max(maxcycle, cycleLength);
                }
            }
        }

        return max(maxcycle, total);
    }
};