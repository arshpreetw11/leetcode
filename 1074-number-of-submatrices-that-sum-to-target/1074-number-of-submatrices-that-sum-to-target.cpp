class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int ans=0;
        for(int top=0;top<r;top++){
            vector<int> col(c,0);
            for(int b=top;b<r;b++){
                for(int j=0;j<c;j++)
                col[j]+=matrix[b][j];
                unordered_map<int,int> mp;
                mp[0]=1;
                int sum=0;
                for(int x:col){
                    sum+=x;
                    if(mp.count(sum-target)){
                        ans+=mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
            
        }
        return ans;
    }
};