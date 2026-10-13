class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        sort(segments.begin(),segments.end());
        vector<vector<long long>> ans;
        map<long long,long long> mp;
        for(auto &s :segments){
            mp[s[0]]+=s[2];
            mp[s[1]]-=s[2];
        }
        long long prev=-1,color=0;

        for(auto &[s,c]:mp){
            if(prev!=-1 && color!=0){
                ans.push_back({prev,s,color});
            }
            color+=c;
            prev=s;
        }
        return ans;
    }
};