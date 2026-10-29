class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> substrings;
        string sub="";
        for(char c:text){
            if(c==' '){
                substrings.push_back(sub);
                sub="";
                continue;
            }
            sub+=c;
        }
        substrings.push_back(sub);
        unordered_map<string,vector<string>> next;
        for(int i=0;i<substrings.size()-1;i++){
            next[substrings[i]].push_back(substrings[i+1]);
        }
        //auto &second=next[first];
        vector<string> res;
        for(int i=0;i+2<substrings.size();i++){
            if(substrings[i]==first && substrings[i+1]==second){
                res.push_back(substrings[i+2]);
            }
        }
        return res;
    }
};