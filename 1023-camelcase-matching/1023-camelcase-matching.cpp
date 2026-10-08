class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(string s: queries){
            int i=0;
            bool b=true;
            for(char c:s){
                if(c>='A' && c<='Z'){
                    if(i>=pattern.size() || pattern[i]!=c){
                        b=false;
                        break;
                    }
                    i++;
                }else{
                    if (i < pattern.size() && pattern[i] == c) {
                        i++;
                    }
                }
            }
            if(i!=pattern.size()) b=false;
            ans.push_back(b);
        }
        return ans;
    }
};