class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mp;
        for(auto & v:paths){
            string a=v[0],b=v[1];
            mp[a]++;
            mp[b]--;
        }
        for(auto &[s,c]:mp){
            if(c<0) return s;
        }
        return "";
    }
};