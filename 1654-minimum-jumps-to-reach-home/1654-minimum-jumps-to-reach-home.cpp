class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> f(forbidden.begin(),forbidden.end());
        queue<pair<int,bool>> q;
        int start=0;
        q.push({start,false});
        int limit=max(x,*max_element(forbidden.begin(),forbidden.end()))+a+b;
        set<pair<int, bool>> vis;
        vis.insert({start,false});
        //a--> forward ,b--> backward;
        int back=0;
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [num,bck] =q.front();
                q.pop();
                if(num==x) return steps;
                int fwd=num+a;
                int bwd=num-b;
                if(!vis.count({fwd,false}) && fwd<=limit && !f.count(fwd)){
                    vis.insert({fwd,false});
                    q.push({fwd,false});
                }
                if(!vis.count({bwd,true}) && bwd>=0 && !f.count(bwd) && !bck ){
                    vis.insert({bwd,true});
                    q.push({bwd,true});
                    
                }
            }
            steps++;
        }
        return -1;
    }
};