class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long ,long long> freq;
        long long  total=0;
        for(int x: wall[0]){
            total+=x;
        }
        for(int i=0;i<wall.size();i++){
            long long prefix=0;
            for(int x: wall[i]){
                prefix+=x;
                freq[prefix]++;
            }
        }
        int mx=0;
        for(auto &[n,f]:freq){
            if(n!=total){
                mx=max((int)mx,(int)f);
            }
        }
        return wall.size()-mx;
    }
};