class Solution {
public:
    int incident(int a,int b,vector<vector<int>>& edges){
        int cnt=0;
        for(auto &e:edges){
            int u=e[0],v=e[1];
            if(a==u || a==v || b==u || b==v) cnt++;
        }
        return cnt;
    }
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        
        vector<int> degree(n+1,0);
        map<pair<int,int>, int> common;
        for(auto &e:edges){
            int u=e[0],v=e[1];
            degree[u]++;
            degree[v]++;
            if(u>v) swap(u,v);
            common[{u,v}]++;
        }

        vector<int> SortedDegree;
        for(int i=1;i<=n;i++){
            SortedDegree.push_back(degree[i]);
        }
        sort(SortedDegree.begin(),SortedDegree.end());

        vector<int> ans;
        for(int q:queries){
            int l=0;
            int r=n-1;
            int cnt=0;
            while(l<r){
                if(SortedDegree[l]+SortedDegree[r]>q){
                    cnt+=r-l;
                    r--;
                }else l++;
            }
            for(auto &[p,shared]:common){
                int u=p.first;
                int v=p.second;
                int total = degree[u] + degree[v];

                if(total > q && total - shared <= q)
                    cnt--;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};