class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n=targets.size();
        string temp=s;
        vector<pair<int,int>> order;
        for(int i=0;i<n;i++){
            order.push_back({indices[i],i});
        }
        sort(order.rbegin(),order.rend());
        for(auto &[idx,i]:order){
            if (s.substr(idx, sources[i].size()) == sources[i]) {
                temp.replace(idx, sources[i].size(), targets[i]);
            }
        }
        return temp;
    }
};