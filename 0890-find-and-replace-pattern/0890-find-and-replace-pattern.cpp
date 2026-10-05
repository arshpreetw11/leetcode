class Solution {
public:
    string flatten(string pattern){
        string flat="";
        char n='a';
        unordered_map<char,char> mp;
        for(char c:pattern){
            if(mp.count(c)){
                flat+=mp[c];
            }else{
                mp[c]=n;
                flat+=mp[c];
                n++;
            }
        }
        return flat;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        string flat=flatten(pattern);

        for(string &word:words){
            if(word.size()!=pattern.size()) continue;
            if(flatten(word)==flat) res.push_back(word);
        }
        return res;
    }
};