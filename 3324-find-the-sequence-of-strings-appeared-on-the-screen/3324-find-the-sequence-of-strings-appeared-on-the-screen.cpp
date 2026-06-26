class Solution {
public:
    vector<string> stringSequence(string target) {
        
        string sub="a";
        vector<string> res;
        
        for(int i=0;i<target.size();i++){
            while(sub[i]!=target[i]){
                res.push_back(sub);
                sub[i]++;
            }
            res.push_back(sub);
            sub.push_back('a');
        }
        return res;
    }
};