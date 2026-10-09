class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> res(s.size());
        for(int i=0;i<indices.size();i++){
            int idx=indices[i];
            res[idx]=s[i];
        }
        string ans="";
        for(char c:res){
            ans+=c;
        }
        return ans;
    }
};