class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<queue<int>> pos(10);
        for(int i=0;i<s.size();i++){
            pos[s[i]-'0'].push(i);
        }
        for(char c:t){
            int x=c-'0';

            if(pos[x].empty()) return false;
            int idx=pos[x].front();
            for(int d=0;d<x;d++){
                if(!pos[d].empty() && pos[d].front()<idx) return false;
            }
            pos[x].pop();
        }
        return true;
    }
};