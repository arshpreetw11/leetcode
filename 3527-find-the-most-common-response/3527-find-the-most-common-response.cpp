class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        string common="";
        unordered_map<string,int> freq;
        for(auto &res: responses){
            sort(res.begin(),res.end());
            res.erase(unique(res.begin(),res.end()),res.end());
            for(string s: res){
                freq[s]++;
            }
        }
        int mx=0;
        for(auto &[s,f]:freq){
            if(mx<f ||(mx==f && common>s)){
                mx=f;
                common=s;
            }
        }
        return common;
    }
};