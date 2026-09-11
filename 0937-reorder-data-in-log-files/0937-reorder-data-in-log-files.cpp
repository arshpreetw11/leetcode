class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string,int>> let,dig;
        for(int i=0;i<logs.size();i++){
            string s=logs[i];
            int pos=s.find(' ');
            string id=s.substr(0,pos);
            string sub=s.substr(pos+1);
            if(isdigit(sub[0])) dig.push_back({sub,i});
            else let.push_back({sub+" "+id,i});
        }
        sort(let.begin(),let.end());
        vector<string> ans;
        for(auto & l:let){
            int i=l.second;
            ans.push_back(logs[i]);
        }
        for(auto & d:dig){
            int i=d.second;
            ans.push_back(logs[i]);
        }
        return ans;
    }
};