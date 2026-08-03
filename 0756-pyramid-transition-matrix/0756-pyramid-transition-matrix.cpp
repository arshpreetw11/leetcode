class Solution {
public:
unordered_map<string,vector<char>> mp;
    bool dfs(string row){
        if(row.size()==1) 
            return true;
        string next="";
        return build(row,0,next);
    }
    bool build(string &row,int idx,string next){
        int sz=row.size();
        if(idx==row.size()-1)
            return dfs(next);
        string key=row.substr(idx,2);
        for(char ch : mp[key]){
            next.push_back(ch);
            if(build(row,idx+1,next))
                return true;
            next.pop_back();
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        
        for(string &s: allowed){
            string x=s.substr(0,2);
            mp[x].push_back(s[2]);
        }
        return dfs(bottom);
    }
};