class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int vol=0;
        int m=heightMap.size(),n=heightMap[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        auto comp=[&](array<int,3>& a,array<int,3>& b){
            return a[0]>=b[0];
        };
        priority_queue<array<int,3>,vector<array<int,3>>,decltype(comp)> min_heap(comp);

        for(int i=0;i<n;i++){
            min_heap.push({heightMap[0][i],0,i});
            min_heap.push({heightMap[m-1][i],m-1,i});
            vis[0][i]=1;
            vis[m-1][i]=1;
        }
        for(int i=0;i<m;i++){
            min_heap.push({heightMap[i][0],i,0});
            min_heap.push({heightMap[i][n-1],i,n-1});
            vis[i][0]=1;
            vis[i][n-1]=1;
        }
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!min_heap.empty()){
            auto [h,r,c]=min_heap.top();
            min_heap.pop();

            for(auto d: dir){
                int nr=r+d[0];
                int nc=c+d[1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    if(h>heightMap[nr][nc]){
                        vol+=h-heightMap[nr][nc];
                    }
                    min_heap.push({max(heightMap[nr][nc],h),nr,nc});
                }
            }

        }
        return vol;
    }
};