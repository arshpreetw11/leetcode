class Solution {
public:
    vector<bool> sus;
    void mark_sus(int k,vector<vector<int>> &adj){
        sus[k]=true;
        for(int v: adj[k]){
            if(!sus[v]){
                mark_sus(v,adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //DIRECTED GRAPH;
        vector<vector<int>> adj(n);
        for(auto &in: invocations){
            int i=in[0];
            int j=in[1];
            adj[i].push_back(j);
        }

        // if k is suspicious then all the nodes that are directly connected with it are also suspicious;
        sus.assign(n,false);
        mark_sus(k,adj);

        bool possible=true;
        for(auto & in: invocations){
            int u=in[0];
            int v=in[1];

            if(!sus[u] && sus[v]){
                possible=false;
                break;
            }
        }
        vector<int> res;
        if(!possible){
            for(int i=0;i<n;i++){
                res.push_back(i);
            }
        }else
        for(int i=0;i<n;i++){
            if(!sus[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};